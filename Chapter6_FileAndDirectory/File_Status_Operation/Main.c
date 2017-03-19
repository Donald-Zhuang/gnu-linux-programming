/***********************************************************/
//     File Name   : main.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sun 19 Mar 2017 01:22:02 PM CST
/**********************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "file_operation.h"

int main(int argc,char *argv[])
{
    struct stat stbuf;
    if( stat(argv[1], &stbuf) == -1 )
    {
        perror(argv[1]);
        return 1;
    }

    printf("Name of file: 5s\n", argv[1]);
    printf("\tDevice: %d\n", (int)stbuf.st_dev);
    printf("\ti_number; %d\n", (int)stbuf.st_ino);
    Print_FileTypeAndPermissions(&stbuf);
    printf("\tLinks: %d\n", stbuf.st_nlink);
    printf("\tFile size: %d\n",(int)stbuf.st_size);
    Print_UserAndGroup(&stbuf);
    Print_AccessModifyChangeTime(&stbuf);
    return 0;
}
