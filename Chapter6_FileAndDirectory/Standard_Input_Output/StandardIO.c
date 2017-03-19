/***********************************************************/
//     File Name   : StandardIO.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sun 19 Mar 2017 11:06:32 AM CST
/**********************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
    char buf[BUFSIZ] = {0,};
    int n = 0;

    while((n = read(STDIN_FILENO, buf, BUFSIZ)) > 0)
    {
        write(STDOUT_FILENO, buf, n);
    }
    return 0;
}
