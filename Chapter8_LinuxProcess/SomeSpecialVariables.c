/***********************************************************/
//     File Name   : SomeSpecialVariables.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Fri 24 Mar 2017 08:26:04 AM CST
/**********************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    extern edata, etext, end;
    printf("end of text segment: %d.\n", (int)&etext);
    printf("end of data segment: %d.\n", (int)&edata);
    printf("end of the uninitialize data segment: %d.\n",(int)&end);
    return 0;
}
