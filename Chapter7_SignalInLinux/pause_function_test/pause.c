/***********************************************************/
//     File Name   : pause.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Wed 22 Mar 2017 08:22:27 AM CST
/**********************************************************/

#include <stdio.h>
#include <signal.h>
void sigint_handler( int signo )
{
    if(signo == SIGINT)
    {
        printf("Catching the SIGINT signal!\n");
        return ;
    }
    else
    {
        printf("Err: Unrecognized Signal!\n");
        return ;
    }
}
int main(int argc,char *argv[])
{
    struct sigaction stact = { };
    sigfillset(&stact.sa_mask);
    stact.sa_handler = sigint_handler;
    sigaction(SIGINT, &stact, NULL);
    printf("INFO: the result of pause is %d\n", pause());
    return 0;
}
