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

void my_on_all_sys_enter(CPUState *cpu, target_ulong pc, target_ulong callno )
{
    const syscall_info_t *t = get_syscall_info( callno );

    printf("SYSCALL PLUGIN: callnumber: %u\n", callno );
    printf("SYSCALL PLUGIN: callname: %s arg count: %d\n", t->name, t->nargs );
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
