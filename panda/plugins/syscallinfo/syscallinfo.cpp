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
#include <iostream>
#include <string>

#include "panda/plugin.h"
#include "panda/plugin_plugin.h"

#include "syscalls2/syscalls2_info.h"
#include "syscalls2/syscalls2_ext.h"
#include "syscalls2/syscalls_ext_typedefs.h"

#include "osi/osi_types.h"

#define MAX_FILENAME 256

extern "C" {

#if defined(TARGET_ARM)

static void displayarg( CPUState *cpu, int argnum, syscall_argtype_t argtype )
{
    switch( argtype )
    {
        case SYSCALL_ARG_U64 :
            {
                uint64_t a = get_64( cpu, argnum );
                printf("%lu ", a );
                break;
            }
        case SYSCALL_ARG_STR :
        case SYSCALL_ARG_PTR :
        case SYSCALL_ARG_U32 :
            {
                uint32_t a = get_32( cpu, argnum );
                printf("%u ", a );
                break;
            }
        case SYSCALL_ARG_S16 : 
        case SYSCALL_ARG_U16 : 
            {
                printf("16: not defined");
                break;
            }
        case SYSCALL_ARG_S64 :
            {
                int64_t a = get_s64( cpu, argnum );
                printf("%ld ", a );
                break;
            }
        case SYSCALL_ARG_S32 : 
            {
                int32_t a = get_s32( cpu, argnum );
                printf("%d ", a );
                break;
            }
        default:
           printf("unknown arg type");
    }
}

static void printargs( CPUState *cpu, int nargs, syscall_argtype_t* argtypes, uint8_t* argsizes )
{
    printf("( ");
    for( int i=0; i<nargs; i++)
    {
        if ( i > 0 )
        {
            printf(", ");
        }
        printf("%d[%d]", (uint32_t)argtypes[i], argsizes[i] );
    }
    printf(" )\n");
    if ( nargs > 0 )
    {
        printf("\targ value: ");
        displayarg( cpu, 0, argtypes[0] );
    }
}

void my_on_all_sys_enter(CPUState *cpu, target_ulong pc, target_ulong callno )
{
    const syscall_info_t *t = get_syscall_info( callno );
    // const syscall_meta_t *m = get_syscall_meta();

    printf("SYSCALL(%u) :\t%s ", callno, t->name );
    printargs( cpu, t->nargs, t->argt, t->argsz );
}

#endif

bool init_plugin(void *self) {
    panda_require("syscalls2");

    if (!init_syscalls2_api()) return false;

#if defined(TARGET_ARM)
    PPP_REG_CB("syscalls2", on_all_sys_enter, my_on_all_sys_enter);
    return true;
#else
    std::cerr << PANDA_MSG "syscallinfo not supported on this arch." << std::endl;
    return false;
#endif
}

void uninit_plugin(void *self) {

}

}
