/***********************************************************/
//     File Name   : PipeFunction.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 25 Mar 2017 12:54:44 PM CST
/**********************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
    char buf[255];
    FILE *fd;
    int line = 1;

    fd = popen("/bin/ls -l", "r");
    //while( fscanf( fd, "%s", buf ) != EOF )
    
    while( fgets( buf, 255, fd ) != NULL )
    {
        printf("line %d: %s", line, buf);
        line++;
    }
    return 0;
}
