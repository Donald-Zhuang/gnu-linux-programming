/***********************************************************/
//     File Name   : execp.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 25 Mar 2017 09:20:19 AM CST
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
    //WARN: the Second string "echo" in parameters is very Necessary in this function!
    char *pEchoParam[] = { "echo","Hello", "world for execvp", "!", (char*)NULL};
    if(fork() == 0)
    {
        execlp("echo", "echo", "Hello", "world 1", "!", (char*)NULL);
        perror("exec one failed!\n");
        exit(0);
    }
    if(fork() == 0)
    {
        execvp("echo", pEchoParam);
        perror("exec one failed!\n");
        exit(0);
    }
    if(fork() == 0)
    {
        execlp("echo", "echo", "Hello", "world 3", "!", (char*)NULL);
        perror("exec one failed!\n");
        exit(0);
    }
    printf("end of process\n");
    return 0;
}
