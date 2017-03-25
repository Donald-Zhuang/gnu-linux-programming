/***********************************************************/
//     File Name   : SetGrpidForChildProcess.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 25 Mar 2017 11:32:30 AM CST
/**********************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void sig_int_handler(int signo)
{
    printf("Process ID[%d],Group ID[%d] get SIGINT.\n", getpid(), getpgrp());
    return ;
}
int main(int argc,char *argv[])
{
    signal(SIGINT, sig_int_handler);
    if(fork() == 0)
    {
        setpgid( 0, getpid() );
    }
    printf("Process ID[%d],Group ID[%d].\n", getpid(), getpgrp());
    pause();
    return 0;
}
