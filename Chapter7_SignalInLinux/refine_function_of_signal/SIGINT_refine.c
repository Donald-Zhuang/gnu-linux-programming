/***********************************************************/
//     File Name   : SIGINT_refine.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Mon 20 Mar 2017 11:33:00 PM CST
/**********************************************************/

#include <stdio.h>
#include <signal.h>
void func_sigint(int signum)
{
    printf("You can stop me by CTRL + C!\n");
    printf("Count down to exit:  \n");
    return ;
}
int main(int argc,char *argv[])
{
    int i;
    signal( SIGINT, func_sigint);
    
    printf("Count down to exit:  \n");
    for(i = 6; i > 0; i--)
    {
        printf("\b\b%d\n", i);
        sleep(1);
    }
    return 0;
}
