/***********************************************************/
//     File Name   : anotherway_to_getenviron.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Fri 24 Mar 2017 10:16:38 PM CST
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    int i;
    extern char **environ;
    for( i=0; envp[i]; i++ )
    {
        puts(envp[i]);
    }
    putenv("DonaldZhuang=/");
    for( i = 0; environ[i]; i++ )
    {
        puts(environ[i]);
    }
    return 0;
}
