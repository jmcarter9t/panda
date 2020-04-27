#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "panda/plugin.h"
#include "panda/plugin_plugin.h"

#include "syscalls2/syscalls2_info.h"
#include "syscalls2/syscalls2_ext.h"
#include "syscalls2/syscalls_ext_typedefs.h"

#include "syscalls2/generated/syscalls_args.h"
#include "syscalls2/syscalls_numbers.h"

#include "osi/osi_types.h"

#define MAX_FILENAME 256

#define OSHEXNUM(VAR) std::showbase << std::hex << (VAR)
#define OSDECNUM(VAR) std::dec << (VAR)
#define OSHEXNUMW(WIDTH,VAR) std::showbase << std::hex << std::internal << std::setfill('0') << std::setw((WIDTH)) << (VAR)
#define OSDECNUMWRT(WIDTH,VAR) std::dec << std::right << std::setfill(' ') << std::setw((WIDTH)) << (VAR)
#define OSDECNUMWLT(WIDTH,VAR) std::dec << std::left << std::setfill(' ') << std::setw((WIDTH)) << (VAR)
#define OSSTR(VAR) std::setfill(' ') << std::left << (VAR)
#define OSSTRWLT(WIDTH,VAR) std::setfill(' ') << std::left << std::setw((WIDTH)) << (VAR)
#define OSSTRWRT(WIDTH,VAR) std::setfill(' ') << std::right << std::setw((WIDTH)) << (VAR)

extern "C" {

    std::ofstream ofs_syscalls;
    std::ofstream ofs_files;

	struct file_data {
		bool status;
        bool load;
		int32_t fd;
		uint32_t flags;
		uint32_t mode;
		uint32_t name_gaddr;
        std::string name;

        // for the make_strings command.
        file_data( bool s, bool l, int32_t fd, uint32_t flags, uint32_t mode, uint32_t addr, const std::string& name )
            : status{ s }
            , load{ l }
            , fd{ fd }
            , flags{ flags }
            , mode{ mode }
            , name_gaddr{ addr }
            , name{ name }
            {}
	};

	// std::unordered_map<std::string,std::shared_ptr<file_data>> file_map;
	std::unordered_map<int32_t,std::shared_ptr<file_data>> fd_map;
    std::unordered_set<int> syscall_ignore_set;
    static bool ioctl_fixup = false;
    static uint32_t ioctl_cmd = 0;

#if defined(TARGET_ARM)


// typedef struct {
//     int no;
//     const char *name;
//     int nargs;
//     syscall_argtype_t *argt;
//     uint8_t *argsz;
//     bool noreturn;
// } syscall_info_t;

static std::string get_guest_string( CPUState* cpu, uint32_t strptr )
{
    static size_t maxbufsz = 256;
    std::string str;
    uint8_t buf[maxbufsz];
    if ( strptr )
    {
        auto rc = panda_virtual_memory_read( cpu, strptr, buf, maxbufsz );
        if ( rc == 0 )
        {
            // there is something to read.
            for( size_t j=0; j<maxbufsz; j++)
            {
                if (buf[j] == 0) break;
                str = str + (char) buf[j];
            }
        }
        else if ( rc == -1 )
        {
            ofs_syscalls << "\n ** UNEXPECTED: no physical page mapped ** \n";
        }
        else
        {
            ofs_syscalls << "\n ** UNEXPECTED: another unexpected memory error ** \n";
        }
    }
    // empty string returned if strptr is null or panda_virtual_memory_read fails.
    return str;
}

static uint32_t get_pointer( uint8_t* buf )
{
    // ARM Little Endian
    uint32_t ptr = (uint32_t)buf[0];
    ptr |= (uint32_t)buf[1] << 8;
    ptr |= (uint32_t)buf[2] << 16;
    ptr |= (uint32_t)buf[3] << 24;

    return ptr;
}

static void log_arguments( size_t arg_index, syscall_argtype_t type, CPUState *cpu, const syscall_ctx_t *ctx )
{
    ofs_syscalls << "\targs[" << OSDECNUM(arg_index) << "] = ";

    switch( type )
    {
        case SYSCALL_ARG_U64:
            {
            unsigned long long arg = *(unsigned long long *) ctx->args[arg_index]; 
            ofs_syscalls << OSDECNUMWLT(20,arg);
            ofs_syscalls << "( " << OSHEXNUMW(18,arg) << " )";
            ofs_syscalls << OSDECNUMWRT(20,"[unsigned 64]");
            }
            break;
        case SYSCALL_ARG_U32:
            {
            unsigned int arg = *(unsigned int *) ctx->args[arg_index]; 
            ofs_syscalls << OSDECNUMWLT(20,arg);
            ofs_syscalls << "( " << OSHEXNUMW(10,arg) << " )";
            ofs_syscalls << OSDECNUMWRT(20,"[unsigned 32]");
            }
            break;
        case SYSCALL_ARG_U16:
            {
            unsigned short arg = *(unsigned short *) ctx->args[arg_index]; 
            ofs_syscalls << OSDECNUMWLT(20,arg);
            ofs_syscalls << "( " << OSHEXNUMW(6,arg) << " )";
            ofs_syscalls << OSDECNUMWRT(20,"[unsigned 16]");
            }
            break;
        case SYSCALL_ARG_S64:
            {
            long long arg = *(long long *) ctx->args[arg_index]; 
            ofs_syscalls << OSDECNUMWLT(20,arg);
            ofs_syscalls << "( " << OSHEXNUMW(20,arg) << " )";
            ofs_syscalls << OSDECNUMWRT(20,"[signed 64]");
            }
            break;
        case SYSCALL_ARG_S32:
            {
            int arg = *(int *) ctx->args[arg_index];
            ofs_syscalls << OSDECNUMWLT(20,arg);
            ofs_syscalls << "( " << OSHEXNUMW(10,arg) << " )";
            ofs_syscalls << OSDECNUMWRT(20,"[unsigned 32]");
            }
            break;
        case SYSCALL_ARG_S16:
            {
            short arg = *(short *)  ctx->args[arg_index]; 
            ofs_syscalls << OSDECNUMWLT(20,arg);
            ofs_syscalls << "( " << OSHEXNUMW(6,arg) << " )";
            ofs_syscalls << OSDECNUMWRT(20,"[signed 16]");
            }
            break;
        case SYSCALL_ARG_PTR:
            {
            void * arg = ( void * )ctx->args[arg_index];
            ofs_syscalls << OSDECNUMWLT(20,arg);
            ofs_syscalls << "( " << OSHEXNUMW(10,arg) << " )";
            ofs_syscalls << OSDECNUMWRT(20,"[pointer]");
            }
            break;
        case SYSCALL_ARG_STR:
            {
                uint8_t buf[256];
                std::string str;

                unsigned int sptr = *( unsigned int *)ctx->args[arg_index];
                panda_virtual_memory_read( cpu, sptr, buf, 256 );
                for( size_t j=0; j<256; j++)
                {
                    if (buf[j] == 0) break;
                    str = str + (char) buf[j];
                }
                ofs_syscalls << OSSTR(str);
                ofs_syscalls << OSSTRWRT(20,"(string)");
            }
            break;
        default:
            {
            ofs_syscalls << "?";
            }
    }
    ofs_syscalls << std::endl;
}

// Runs after all other enter callbacks.
void my_on_all_sys_enter2(CPUState *cpu, target_ulong pc, const syscall_info_t *call, const syscall_ctx_t *ctx)
{
    // The return address is the address that will be executed upon completion of the 
    // system call.
    // ofs_syscalls << " rtn addr = " << std::hex << ctx->retaddr;

    if ( !call || !ctx ) return;

    // just skip the system calls we handle directly.
    if ( syscall_ignore_set.find( call->no ) != syscall_ignore_set.end() ) return;

    // call is populated correctly for a specific call from dso_info_linux_arm.c
    // should be able to lookup args.
    char prev = ofs_syscalls.fill();

    ofs_syscalls << "[SYSCALL ENTER (" << OSDECNUM(call->no) << ")]: " << OSSTRWLT( 20, call->name );
    ofs_syscalls << "PC = " << OSHEXNUMW(10,pc);
    ofs_syscalls << " PID = " << OSHEXNUMW(10,ctx->asid);
    ofs_syscalls << std::endl;

    for( int i=0; i<call->nargs; i++ ) 
    {
        log_arguments( i, call->argt[i], cpu, ctx );
    }

    ofs_syscalls.fill(prev);
}

// Runs after all other return callbacks.
void my_on_all_sys_return2(CPUState *cpu, target_ulong pc, const syscall_info_t *call, const syscall_ctx_t *ctx)
{
    if ( !call || !ctx ) return;

    // just skip the system calls we handle directly.
    if ( syscall_ignore_set.find( call->no ) != syscall_ignore_set.end() ) return;

    // call is populated correctly for a specific call from dso_info_linux_arm.c
    // should be able to lookup args.
    char prev = ofs_syscalls.fill();

    ofs_syscalls << "[SYSCALL RETURN (" << OSDECNUM(call->no) << ")]: " << OSSTR( call->name ) << std::endl;

    // return values from functions are stored in R0 and R1
    CPUArchState *cas = (CPUArchState *)cpu->env_ptr;
    int32_t rc = cas->regs[0];
    ofs_syscalls << "\trtn value = " << OSDECNUMWLT(20,rc);
    ofs_syscalls << "( " << OSHEXNUM((uint32_t)rc) << " )";
    ofs_syscalls << std::endl;

    ofs_syscalls.fill(prev);
}

void my_on_sys_execve_enter(CPUState* cpu, target_ulong pc, uint32_t filename, uint32_t argv, uint32_t envp)
{
    // swag on the max number of arguments.
    size_t bufsz = 20*sizeof(uint32_t);
    uint8_t abuf[bufsz];
    uint8_t ebuf[bufsz];

    char prev = ofs_syscalls.fill();

    ofs_syscalls << "[EXECVE ENTER]: ";
    std::string fn = get_guest_string( cpu, filename );
    ofs_syscalls << "filename = " << fn << std::endl;

    panda_virtual_memory_read( cpu, argv, abuf, bufsz );
    for (int i=0; i<20; i++)
    {
        uint32_t ptr = get_pointer( &abuf[i*4] );
        if ( ptr == 0 ) break;
        std::string arg = get_guest_string( cpu, ptr );
        // ofs_syscalls << "\targv[" << std::hex << ptr << "] = ";

        ofs_syscalls << "\targv[" << OSHEXNUMW(10,ptr) << "] = ";
        ofs_syscalls << OSDECNUM(arg) << std::endl;
    }

    panda_virtual_memory_read( cpu, envp, ebuf, bufsz );
    for (int i=0; i<20; i++)
    {
        uint32_t ptr = get_pointer( &ebuf[i*4] );
        if ( ptr == 0 ) break;
        std::string arg = get_guest_string( cpu, ptr );
        // ofs_syscalls << "\tenvp[" << std::hex << ptr << "] = ";
        ofs_syscalls << "\tenvp[" << OSHEXNUMW(10,ptr) << "] = ";
        ofs_syscalls << OSDECNUM(arg) << std::endl;
    }

    ofs_syscalls.fill(prev);
}

void my_on_sys_execve_return(CPUState* cpu, target_ulong pc, uint32_t filename, uint32_t argv, uint32_t envp)
{
    ofs_syscalls << "[EXECVE RETURN]: Only on error" << std::endl;
}

void my_on_sys_ioctl_enter(CPUState* cpu, target_ulong pc, uint32_t fd, uint32_t cmd, uint32_t arg)
{
    size_t bufsz = 256;
    uint8_t buf[bufsz];
    std::string filename;

    ofs_syscalls << "[IOCTL ENTER]:  fd = " << OSDECNUMWLT(6,fd) << " cmd = " << OSHEXNUMW(10,cmd) << " arg = " << OSHEXNUMW(10,arg) << " pc = " << OSHEXNUM(pc) << std::endl;

    auto search = fd_map.find( fd );
    if ( search == fd_map.end() )
    {
        filename = "<unknown>";
    }
    else
    {
        filename = search->second->name;
    }
    ofs_syscalls << "\tfilename = " << filename << std::endl;

    // the last parameter can be anything really, sometimes it is ascii data and that might be useful.
    // Would be nice to have this display HEX and ASCII like hexdump.
    panda_virtual_memory_read( cpu, arg, buf, bufsz );
    for (size_t i=0; i<bufsz; i++)
    {
        if ( buf[i] == 0 ) break;
        ofs_syscalls << "\tvargs["<<i<<"] = " << OSHEXNUM( buf[i] ) << std::endl;
        ofs_syscalls << std::dec;
    }
}

void my_on_sys_ioctl_return(CPUState* cpu, target_ulong pc, uint32_t fd, uint32_t cmd, uint32_t arg)
{
    std::string filename;
    ofs_syscalls << "[IOCTL RETURN]: fd = " << OSDECNUMWLT( 6, fd ) << " cmd = " << OSHEXNUMW(10,cmd) << " arg = " << OSHEXNUMW(10,arg) << " pc = " << OSHEXNUM(pc) << std::endl;

    auto search = fd_map.find( fd );
    if ( search == fd_map.end() )
    {
        filename = "<unknown>";
    }
    else
    {
        filename = search->second->name;
    }
    ofs_syscalls << "\tfilename = " << filename << std::endl;

    CPUArchState *cas = (CPUArchState *)cpu->env_ptr;
    ofs_syscalls << "\tReturn Value = " << cas->regs[0] << std::endl;

    if ( ioctl_cmd > 0 )
    {
        if ( cmd == ioctl_cmd )
        {
            // this is the /dev/dsa ioctl call. We know this by backtracking the file descriptor (3).

            // return values from functions are stored in R0 and R1

            CPUArchState *cas = (CPUArchState *)cpu->env_ptr;
            ofs_syscalls << "\tForcing return value change to 0 (success)." << std::endl;
            cas->regs[0] = 0;

        }
    }

//    if ( cmd == 0x40046401 )
//    {
//        // this is the /dev/dsa ioctl call. We know this by backtracking the file descriptor (3).
//
//        // return values from functions are stored in R0 and R1
//
//        CPUArchState *cas = (CPUArchState *)cpu->env_ptr;
//        ofs_syscalls << "\tForcing return value change to 0 (success)." << std::endl;
//        cas->regs[0] = 0;
//    }
}

/**
 * NOTE: Sometimes the guest page with the address of the filename is not in memory, so the get_guest_string call will
 * fail. This IS UNEXPECTED, so we will change things to do our bookkeeping in the open return.
 *
 */
void my_on_sys_open_enter(CPUState* cpu, target_ulong pc, uint32_t filename, int32_t flags, uint32_t mode)
{
    // ofs_syscalls << "Panda In Kernel: " << panda_in_kernel(cpu) << std::endl;
    std::string fn = get_guest_string( cpu, filename );
    ofs_syscalls << "[OPEN ENTER] " << fn << " @ " << OSHEXNUMW(10,filename) << std::endl;

    if ( fn.empty() )
    {
        ofs_syscalls << "\tWARNING filename is empty ( string ptr == null or panda_virtual_memory_read fails )." << std::endl;
    }
}

void my_on_sys_open_return(CPUState* cpu, target_ulong pc, uint32_t filename, int32_t flags, uint32_t mode)
{
    // ofs_syscalls << "Panda In Kernel: " << panda_in_kernel(cpu) << std::endl;
    std::string fn = get_guest_string( cpu, filename );

	ofs_syscalls << "[OPEN RETURN] " << fn << " @ " << OSHEXNUMW(10,filename) << std::endl;

    // return code from open.
    CPUArchState *cas = (CPUArchState *)cpu->env_ptr;
    // When negative, its positive corresponds to the errno in errno.h (looks like).
    int32_t rc = (int32_t)cas->regs[0];

    if ( rc >= 0 )
    {
        auto search = fd_map.find( rc );
        if ( search != fd_map.end() )
        {
            ofs_syscalls << "\tWARNING: recycling a file descriptor that should have been closed." << std::endl;
        }

        fd_map[rc] = std::make_shared<file_data>( true, true, rc, flags, mode, filename, fn ); 
        ofs_syscalls << "\topen success fd = " << OSDECNUM(rc);
        ofs_syscalls << " flags = " << OSHEXNUMW(10, flags );
        ofs_syscalls << " mode = " << OSHEXNUMW(10, mode );
        ofs_syscalls << std::endl;
    }
    else
    {
        ofs_syscalls << "open failed with code = " << OSDECNUM(rc) << std::endl;
    }

    ofs_syscalls << std::dec << std::noshowbase;
}

void my_on_sys_close_enter(CPUState* cpu, target_ulong pc, uint32_t fd)
{
}

void my_on_sys_close_return(CPUState* cpu, target_ulong pc, uint32_t fd)
{
    int32_t key = (int32_t) fd;
    auto search = fd_map.find( key );

    ofs_syscalls << "CLOSE RETURN [" << OSDECNUM(key) << "]: ";


    if ( search == fd_map.end() )
    {
        ofs_syscalls << "WARNING: no fd_map entry!";
    }
    else
    {
        ofs_syscalls << search->second->name;
        //        auto m = fd_map.erase( key );
    }
    ofs_syscalls << std::endl;
}


/**
 * Return true -> filter this file.
 */
bool file_filter( const std::string& filename )
{
    bool rc = ( filename.rfind( ".so" ) != std::string::npos );
    return rc;
}

static void log_file_read_data(CPUState* cpu, uint32_t gbuf, uint32_t count, bool dumpfile )
{
    static size_t maxbufsz = 1024;
    uint8_t hbuf[maxbufsz];

    std::stringstream ss;
    ss << "\n===== begin file contents [" << count << "] bytes =====\n";

    if ( dumpfile ) 
    {
        while ( count > 0 )
        {
            size_t n = ( count > maxbufsz ) ? maxbufsz : count;
            // returns 0 on success.
            auto rc = panda_virtual_memory_read( cpu, gbuf, hbuf, n );
            if ( rc ) break;

            for( size_t j=0; j<n; j++)
            {
                ss << (char) hbuf[j];
            }
            gbuf += n;
            count -= n;
        }
    }
    else 
    {
        ss << "\t>>> not displayed for brevity <<<";
        count = 0;
    }

    ss << "\n===== end file contents [" << count << "] bytes remaining =====\n";
    ofs_syscalls << ss.str() << std::endl;
}

static void log_file_write_data(CPUState* cpu, uint32_t gbuf, uint32_t count )
{
    static size_t maxbufsz = 1024;
    uint8_t hbuf[maxbufsz];

    std::stringstream ss;
    ss << "\n===== begin write contents [" << count << "] bytes =====\n";

    while ( count > 0 )
    {
        size_t n = ( count > maxbufsz ) ? maxbufsz : count;
        // returns 0 on success.
        auto rc = panda_virtual_memory_read( cpu, gbuf, hbuf, n );
        if ( rc ) break;

        for( size_t j=0; j<n; j++)
        {
            ss << (char) hbuf[j];
        }
        gbuf += n;
        count -= n;
    }

    ss << "\n===== end write contents [" << count << "] bytes remaining =====\n";
    ofs_syscalls << ss.str() << std::endl;
}

void my_on_sys_read_enter(CPUState* cpu, target_ulong pc, uint32_t fd, uint32_t buf, uint32_t count)
{
    int32_t key = (int32_t) fd;
    auto search = fd_map.find( key );

    ofs_syscalls << "READ ENTER [" << OSDECNUM(key) << "]: ";

    if ( search != fd_map.end() )
    {
        auto fdptr = search->second;
        ofs_syscalls << fdptr->name << " read count = " << OSDECNUM(count) << " into buf = " << OSHEXNUMW(10,buf) << std::endl;
        // should we load this file.
        fdptr->load = !file_filter( fdptr->name );
    }
    else
    {
        ofs_syscalls << "\tERROR: file descriptor not in the map" << std::endl;
    }
}

void my_on_sys_read_return(CPUState* cpu, target_ulong pc, uint32_t fd, uint32_t gbuf, uint32_t count)
{
    // return code from open.
    CPUArchState *cas = (CPUArchState *)cpu->env_ptr;
    // When negative, its positive corresponds to the errno in errno.h (looks like).
    // this should be the number of bytes read.
    int32_t rc = (int32_t)cas->regs[0];

    ofs_syscalls << "READ RETURN [" << OSDECNUM(fd) << "]: " << OSDECNUM(count) << " bytes; return code = " << OSDECNUM(rc) << std::endl;

    if ( rc > 0 )
    {
        int32_t key = (int32_t) fd;
        auto search = fd_map.find( key );
        if ( search != fd_map.end() )
        {
            auto fdptr = search->second;
            log_file_read_data( cpu, gbuf, rc, fdptr->load );
        }
        else
        {
            ofs_syscalls << "\nWARNING: File Descriptor Not Found!" << std::endl;
        }
    }
    else if ( rc == 0 )
    {
        ofs_syscalls << "\tINFO: End of File Reached; no bytes read." << std::endl;
    }
    else
    {
        ofs_syscalls << "\tERROR: Read return code: " << rc << " no bytes read." << std::endl;
    }
}

void my_on_sys_write_enter(CPUState* cpu, target_ulong pc, uint32_t fd, uint32_t buf, uint32_t count)
{
    int32_t key = (int32_t) fd;
    auto search = fd_map.find( key );

    ofs_syscalls << "WRITE ENTER [" << OSDECNUM(key) << "]: ";

    if ( search != fd_map.end() )
    {
        auto fdptr = search->second;
        ofs_syscalls << fdptr->name << " write count = " << OSDECNUM(count) << " from buf = " << OSHEXNUMW(10,buf) << std::endl;
    }
    else
    {
        ofs_syscalls << "\tERROR: file descriptor not in the map." << std::endl;
    }

}

void my_on_sys_write_return(CPUState* cpu, target_ulong pc, uint32_t fd, uint32_t gbuf, uint32_t count)
{
    // return code from open.
    CPUArchState *cas = (CPUArchState *)cpu->env_ptr;
    // When negative, its positive corresponds to the errno in errno.h (looks like).
    // this should be the number of bytes read.
    int32_t rc = (int32_t)cas->regs[0];

    ofs_syscalls << "WRITE RETURN [" << OSDECNUM(fd) << "]: " << OSDECNUM(count) << " byte(s); return code = " << OSDECNUM(rc) << std::endl;

    if ( rc > 0 )
    {
        int32_t key = (int32_t) fd;
        auto search = fd_map.find( key );
        if ( search != fd_map.end() )
        {
            auto fdptr = search->second;
            log_file_write_data( cpu, gbuf, rc );
        }
        else
        {
            ofs_syscalls << "\nWARNING: File Descriptor Not Found!" << std::endl;
        }
    }
    else if ( rc == 0 )
    {
        ofs_syscalls << "\tINFO: No bytes written." << std::endl;
    }
    else
    {
        ofs_syscalls << "\tERROR: Write return code: " << rc << " no bytes written." << std::endl;
    }
}

#endif

bool init_plugin(void *self) {
    panda_require("syscalls2");

    if (!init_syscalls2_api()) return false;

#if defined(TARGET_ARM)
    // used to register my plugin's callback (B) into the base plugin syscalls2 (A)
    // Adds my callback into the list of callbacks that will be called when on_all_sys_enter2
    // is called.
    
    // parse arguments and initialize callbacks & info api
    panda_arg_list *plugin_args = panda_get_args(PLUGIN_NAME);

    // load system call info
    // uint32_t
    ioctl_fixup = panda_parse_bool_opt(plugin_args, "ioctl-fixup-all", "return true for all ioctl calls that return an error code.");
    ioctl_cmd = panda_parse_uint32(plugin_args, "ioctl-cmd", 0 );
    
	PPP_REG_CB("syscalls2", on_all_sys_enter2, my_on_all_sys_enter2);
	PPP_REG_CB("syscalls2", on_all_sys_return2, my_on_all_sys_return2);
	PPP_REG_CB("syscalls2", on_sys_ioctl_enter, my_on_sys_ioctl_enter );
	PPP_REG_CB("syscalls2", on_sys_ioctl_return, my_on_sys_ioctl_return );
	PPP_REG_CB("syscalls2", on_sys_execve_enter, my_on_sys_execve_enter );
	PPP_REG_CB("syscalls2", on_sys_execve_return, my_on_sys_execve_return );
	PPP_REG_CB("syscalls2", on_sys_open_enter, my_on_sys_open_enter);
	PPP_REG_CB("syscalls2", on_sys_open_return, my_on_sys_open_return);
	PPP_REG_CB("syscalls2", on_sys_close_enter, my_on_sys_close_enter);
    PPP_REG_CB("syscalls2", on_sys_close_return, my_on_sys_close_return);
    PPP_REG_CB("syscalls2", on_sys_read_enter, my_on_sys_read_enter);
    PPP_REG_CB("syscalls2", on_sys_read_return, my_on_sys_read_return);
	PPP_REG_CB("syscalls2", on_sys_write_enter, my_on_sys_write_enter);
	PPP_REG_CB("syscalls2", on_sys_write_return, my_on_sys_write_return);

    syscall_ignore_set.emplace( syscalls2::linux::arm::sys_read );
    syscall_ignore_set.emplace( syscalls2::linux::arm::sys_write );
    syscall_ignore_set.emplace( syscalls2::linux::arm::sys_execve );
    syscall_ignore_set.emplace( syscalls2::linux::arm::sys_ioctl );
    syscall_ignore_set.emplace( syscalls2::linux::arm::sys_open );
    syscall_ignore_set.emplace( syscalls2::linux::arm::sys_close );

    ofs_syscalls.open( "syscall.output.log", std::ios_base::out | std::ios_base::trunc );
    ofs_files.open( "syscall.files.log", std::ios_base::out | std::ios_base::trunc );

    std::shared_ptr<file_data> info = std::make_shared<file_data>( true, true, 0, 0, 0, 0, "stdin" );
	// file_map.emplace( "stdin", info );	
    fd_map.emplace( 0, info );

    info = std::make_shared<file_data>( true, true, 1, 0, 0, 0, "stdout" );
	// file_map.emplace( "stdout", info );	
    fd_map.emplace( 1, info );

    info = std::make_shared<file_data>( true, true, 2, 0, 0, 0, "stderr" );
	// file_map.emplace( "stderr", info );	
    fd_map.emplace( 2, info );

    return true;
#else
    std::cerr << PANDA_MSG "syscallinfo not supported on this arch." << std::endl;
    return false;
#endif
}

void uninit_plugin(void *self) {
    ofs_syscalls.close();
    ofs_files.close();
}

}
