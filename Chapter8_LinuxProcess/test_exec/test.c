/***********************************************************/
//     File Name   : test.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 25 Mar 2017 08:46:32 AM CST
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>

int global = 0;
extern char **environ;

int main(int argc,char *argv[])
{
    int local = 1;
    int i = 0;
    
    printf("&local = %8x, &global = %8x\n", (int)&local, (int)&global);
    for( i = 0; i < argc; i++ )
    {
        printf("argv[%d] = %s\n", i, *(argv+i));
    }
    for( i = 0; *(environ + i); i++)
    {
        printf("%s\n", *(environ + i) );
    }
    return 0;
}
