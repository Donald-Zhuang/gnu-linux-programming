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
void sig_int_handler(int signo)
{
    printf("process[%d] get SIGINT\n", getpid());
    return ;
}
int main(int argc,char *argv[])
{
    pid_t pid;
    signal(SIGINT, sig_int_handler);

    if((pid = fork()) == 0)
    {
        printf("child process[%d](group[%d]) pause.\n", getpid(), getpgrp());
    }else{
        printf("parent process[%d](group[%d]) pause.\n", getpid(), getpgrp());
    }
    pause();
    return 0;
}
