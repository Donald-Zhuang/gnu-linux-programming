/***********************************************************/
//     File Name   : process_sync.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 25 Mar 2017 10:14:04 AM CST
/**********************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

static int TestGlobal = 0;
void sig_alarm_handler(int signo)
{
    if(signo == SIGALRM)
    {
        printf("child process[%4d]: %d\n", getpid(), TestGlobal);
        exit(0);
    }
}
int process_exit(int status)
{
    if( 0 != WIFEXITED(status) )
    {
        printf("INFO: normal termination, exit code: %d.\n", WEXITSTATUS(status));
        return 1;
    }
    else if( 0 != WIFSIGNALED(status) )
    {
        printf("INFO: signal termination, signal NO: %d.\n", WTERMSIG(status));
        return 1;
    }
    else if( 0 != WIFSTOPPED(status) )
    {
        printf("INFO: stopped status, signal NO: %d.\n", WSTOPSIG(status));
    }
    return 0;
}
int main(int argc,char *argv[])
{
    pid_t pid[5], wpid;
    int i, child_status, flag= 5;
    struct sigaction stsig;
    
    stsig.sa_handler = sig_alarm_handler;
    sigemptyset(&stsig.sa_mask);
    stsig.sa_flags = 0;

    for ( i = 0; i < 5; i++ )
    {
        if( (pid[i] = fork()) == 0 )
        {
            TestGlobal++; // test for operation of global variable
            sigaction(SIGALRM, &stsig, NULL);
            alarm(i+1);
            pause();

            /* the same funtion
            signal(SIGALRM, sig_alarm_handler);
            sleep(i+1);
            */
            exit(i); //for abnomal interupt signal
        }
    }
    while(flag) 
    {
        for( i = 0; i < 5; i++ )
        {
            if (waitpid(pid[i], &child_status, WNOHANG) == pid[i])
            {
                flag -= process_exit(child_status);
            }
        }
    }
    return 0;
}
