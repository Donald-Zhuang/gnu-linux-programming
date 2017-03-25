/***********************************************************/
//     File Name   : exec.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 25 Mar 2017 08:54:56 AM CST
/**********************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    printf("Before exec\n");
    execl("./test", "param1", "param2", "param3", (char*)NULL );
    printf("After exec\n"); // this will never be executed.  
    return 0;
}
