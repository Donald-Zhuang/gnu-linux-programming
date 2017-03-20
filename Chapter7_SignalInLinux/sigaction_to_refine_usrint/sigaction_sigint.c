/***********************************************************/
//     File Name   : sigaction_sigint.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Tue 21 Mar 2017 12:28:17 AM CST
/**********************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void func_sigint(int signo)
{
    printf("INFO: Catching SIGINT\n");
    return ;
}
void func_sigusr1(int signo)
{
    int i = 0; 
    printf("INFO: Catching SIGUSR1, Mask all the other signal!\nCount down 10s to exit process!\n");
    for( i = 10; i > 0; i-- )
    {
        sleep(1);
    }
    printf("WARN: Exit the process!\n");
    exit(0);
}
int main(int argc,char *argv[])
{
    struct sigaction stsigint, stsigusr1;
    stsigint.sa_handler = func_sigint;
    sigemptyset( &stsigint.sa_mask );
    stsigint.sa_flags = 0;
    sigaction( SIGINT, &stsigint, 0);

    stsigusr1.sa_handler = func_sigusr1;
    sigfillset( &stsigusr1.sa_mask );
    stsigusr1.sa_flags = 0;
    sigaction( SIGUSR1, &stsigusr1, 0);

    while(1)
    {
        sleep(1);
    }
    return 0;
}
