/***********************************************************/
//     File Name   : linux_environmental_variables.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Fri 24 Mar 2017 08:32:37 AM CST
/**********************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    extern char **environ;
    int i = 0;
    for(i = 0; *(environ+i) != NULL; i++)
    {
        printf("%s\n", *(environ+i));
    }
    return 0;
}
