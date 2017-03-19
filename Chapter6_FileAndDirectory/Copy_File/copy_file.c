/***********************************************************/
//     File Name   : copy_file.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sun 19 Mar 2017 11:19:49 AM CST
/**********************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILE_MODE (0644)

int main(int argc,char *argv[])
{
    int fdin = -1, fdout = -1, n = 0;
    char buf[BUFSIZ] = {0,};

    if(argc != 3)
    {
        fprintf( stderr,"Usage:\n\t%s <FileIn> <FileOut>\n", argv[0] );
        return 0;
    }

    if( (fdin = open(argv[1], O_RDONLY)) == -1 )
    {
        perror(argv[1]);
        return 2;
    }

    if( (fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE)) == -1 )
    {
        perror(argv[2]);
        return 3;
    }
    
    while( (n = read(fdin, buf, BUFSIZ)) > 0 )
    {
        write( fdout, buf, n );
    }
    return 0;
}
