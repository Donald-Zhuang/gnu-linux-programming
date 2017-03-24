/***********************************************************/
//     File Name   : fork_function.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Fri 24 Mar 2017 11:25:00 PM CST
/**********************************************************/

#include <stdio.h>
#include <sys/types.h>

int glob = 9;

int main(int argc,char *argv[])
{
    int local = 8;
    pid_t pid = 0;

    printf("The pid of parent process is %d.\n", getpid());
    if( (pid = fork()) == 0 )
    {
        // the child process will run here.
        sleep(2);
    }
    else
    {
        // the parent process will run here.
        glob++;
        local--;
        sleep(10);
    }
    printf("pid = %d, glob = %d, local = %d.\n",getpid(), glob, local);
    return 0;
}
