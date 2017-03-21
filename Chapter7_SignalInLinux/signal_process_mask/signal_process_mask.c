/***********************************************************/
//     File Name   : signal_process_mask.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Tue 21 Mar 2017 07:57:48 AM CST
/**********************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int cntdwn = 6;
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigprocmask(SIG_BLOCK, &set, NULL);
    
    printf("WARN: mask the SIGINT.\n");
    while(cntdwn--)
    {
        printf("INFO: Count down to Exit! : %d\n", cntdwn);
        sleep(1);
    }
    
    sigprocmask(SIG_UNBLOCK, &set, NULL);
    printf("INFO: Demo Exit!\n");
    return 0;
}   
