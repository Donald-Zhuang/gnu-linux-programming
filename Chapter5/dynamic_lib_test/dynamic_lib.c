/***********************************************************/
//     File Name   : dynamic_lib.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 18 Mar 2017 09:21:57 PM CST
/**********************************************************/

#include <stdio.h>
//#include "test.h"
#include "dlfcn.h"
#include <stdlib.h>

#define DlErr_PrintAndExit(cond)        \
    do{                                 \
        char *err=dlerror();            \
        if(#cond && err!=NULL)          \
        {                               \
            fputs(err, stderr);         \
            exit(1);                    \
        }                               \
    }while(0)
#define TRUE (1)

int main(int argc,char *argv[])
{
    int (*add)(int, int);
    int (*max)(int, int);

    void *handle = NULL;
    char *err;
    int num1 = 1, num2 = 2;
    
    handle = dlopen("./libdemo.so", RTLD_LAZY);
    DlErr_PrintAndExit( NULL == handle );

    add = dlsym(handle, "add");
    DlErr_PrintAndExit( TRUE );

    max = dlsym(handle, "max");
    DlErr_PrintAndExit( TURE );

    printf("the plus: %d + %d = %d\n", num1, num2, add(num1, num2));
    printf("the max of %d and %d: %d\n", num2, num1, max(num1, num2));
    return 0;
}
