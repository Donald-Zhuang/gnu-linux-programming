/***********************************************************/
//     File Name   : AnonymousPipo.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 25 Mar 2017 12:40:40 PM CST
/**********************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    pid_t pid;
    int fd_arr[2], i;
    char ch;
    pipe(fd_arr);
    if( (pid = fork()) == 0 )
    {
        close(fd_arr[1]);
        for(i = 0; i < 10; i++)
        {
            read(fd_arr[0], &ch, 1);
            putchar(ch);
        }
        close(fd_arr[0]);
        exit(0);
    }else{
        close(fd_arr[0]);
        for(i = 0; i < 10; i++)
        {
            ch = 'a' + i;
            write(fd_arr[1],&ch, 1);
        }
        close(fd_arr[1]);
    }
    return 0;
}
