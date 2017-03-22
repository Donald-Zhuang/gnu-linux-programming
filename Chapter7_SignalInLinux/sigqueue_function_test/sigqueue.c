/***********************************************************/
//     File Name   : sigqueue.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Wed 22 Mar 2017 08:00:02 AM CST
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void sighandler(int signo, siginfo_t *pstinfo, void *context)
{
    printf("%s\n",(char *) pstinfo->si_value.sival_ptr);
    return ;
}
int main(int argc,char *argv[])
{
    struct sigaction stsigact = {};
    sigval_t val;
    char sMsg[] = "Hello world!\n";

    stsigact.sa_flags = SA_SIGINFO;
    stsigact.sa_sigaction = sighandler;
    if( sigaction(SIGUSR1, &stsigact, NULL) == -1 )
    {
        printf("ERR: error to set sighandler!\n");
        exit(1);
    }
    val.sival_ptr = (void*)sMsg;
    if(sigqueue(getpid(), SIGUSR1, val) == -1)
    {
        printf("ERR: sigqueue excute failed!\n");
        exit(2);
    }
    sleep(3);
    return 0;
}
