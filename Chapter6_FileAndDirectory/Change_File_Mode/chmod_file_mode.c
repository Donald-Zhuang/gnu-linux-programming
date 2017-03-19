/***********************************************************/
//     File Name   : chmod_file_mode.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sun 19 Mar 2017 09:44:44 PM CST
/**********************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
    mode_t file_mode = (S_IRWXG | S_IRWXU | S_IRWXO);
    
    if(argc < 2)
    {
        printf("Usage:\n\tUsing this bin change file mode to 0777\n\t%s <filename>\n", argv[0]);
        return 1;
    }
    if( chmod(argv[1], file_mode) == -1)
    {
        printf("ERR: chmod failed!\n");
        return 1;
    }

    return 0;
}
