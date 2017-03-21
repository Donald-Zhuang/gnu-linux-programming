/***********************************************************/
//     File Name   : trace_blocking_signal.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Tue 21 Mar 2017 08:15:48 AM CST
/**********************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    sigset_t set, pendingset;
    struct sigaction action;

    sigemptyset(&set);
    sigaddset(&set, SIGTERM);
    sigprocmask(SIG_BLOCK, &set, NULL);
    kill( getpid(), SIGTERM );
    sigpending(&pendingset);
    if(sigismember(&pendingset, SIGTERM))
    {
        printf("INFO: The SIGTERM is been blocked!\n");
    }
    sigprocmask(SIG_UNBLOCK, &set, NULL);
    int cntdwn = 5;
    while (cntdwn--)
    {
        printf("INFO: Count down to exit! : %d\n", cntdwn);
        sleep(1);
    }
    return 0;
}
