/***********************************************************/
//     File Name   : usrsignal_example.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Mon 20 Mar 2017 11:58:43 PM CST
/**********************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void func_usrsig(int signo)
{
    if( signo == SIGUSR1 )
    {
        printf("Signal SIGUSR1 is been catched!\n");
    }
    else if( signo == SIGUSR2 )
    {
        printf("Signal SIGUSR2 is been catched!\n");
        printf("INFO:exit this demo!\n");
        exit(0);
    }
    else
    {
        printf("ERR: Unreconigizd Signal!\n");
        exit(1);
    }
    return ;
}
int main(int argc,char *argv[])
{
    printf("Usage:\n\tRun this demo in background by \"%s &\"\n\t"
            "Send command \"kill -s SIGUSR1/SIGUSR2 [pid]\"\n",argv[0]);
    if( signal( SIGUSR1, func_usrsig ) == SIG_ERR )
    {
        printf("ERR: Can't catch SIGUSR1!\n");
    }

    if( signal( SIGUSR2, func_usrsig ) == SIG_ERR )
    {
        printf("ERR: Can't catch SIGUSR2!\n");
    }
    while(1)
    {
        sleep(1);
    }
    return 0;
}
