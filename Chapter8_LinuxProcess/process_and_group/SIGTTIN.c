/***********************************************************/
//     File Name   : process_group.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 25 Mar 2017 11:19:30 AM CST
/**********************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_ttin_handler(int signo)
{
    printf("process[%d] get SIGTTIN\n", getpid());
    signal(SIGTTIN, SIG_DFL);
    //exit(0);
    //return ; //this cmd is false
}
void sig_int_handler(int signo)
{
    printf("process[%d] get SIGINT\n", getpid());
}
int main(int argc,char *argv[])
{
    pid_t pid;
    int status, in_num;

    if((pid = fork()) == 0)
    {
        signal(SIGTTIN, sig_ttin_handler);
        signal(SIGINT, sig_int_handler);
        setpgid( 0, getpid());
        printf("please input a string:\n");
        scanf("%d", &in_num);
        printf("child process[%d] group[%d]) input: %d.\n", getpid(), getpgrp(), in_num);
    }else{
        wait(&status);
    }
    return 0;
}
