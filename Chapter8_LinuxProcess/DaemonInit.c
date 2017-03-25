/***********************************************************/
//     File Name   : DaemonInit.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 25 Mar 2017 12:07:44 PM CST
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int daemon_init( void )
{
    pid_t pid;
    if((pid = fork()) < 0)
    {
        return -1;
    }
    else if (pid > 0)
    {
        exit(0);
    }
    printf("Daemon PID[%d].\n", getpid());
    setsid();
    chdir("/");
//    system("cd /");
    umask(0);
    close(0);
    close(1);
    close(2);
    return 0;

}
int main(int argc,char *argv[])
{
    daemon_init();
    while(1)
        ;
    return 0;
}
