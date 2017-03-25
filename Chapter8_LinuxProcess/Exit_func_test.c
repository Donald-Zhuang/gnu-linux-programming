/***********************************************************/
//     File Name   : Exit_func_test.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 25 Mar 2017 08:11:27 AM CST
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static void my_exit_handler1( void )
{
    printf("exit function1\n");
}
static void my_exit_handler2( void )
{
    printf("exit function2\n");
}

int main(int argc,char *argv[])
{
    if(atexit(my_exit_handler1) != 0)
    {
        printf("ERR:Register my_exit_handler1 failed!\n");
    }
    if(atexit(my_exit_handler1) != 0)
    {
        printf("ERR:Second time to register my_exit_handler1 failed!\n");
    }
    if(atexit(my_exit_handler2) != 0)
    {
        printf("ERR:Register my_exit_handler2 failed!\n");
    }
    if(argc > 1)
    {
        if( strcmp(argv[1], "1") == 0 )
        {
            printf("the mode of exit!\nThere is a message in the following:\n");
            printf("Hello world!");
            exit(0);
        }
        if( strcmp(argv[1], "2") == 0 )
        {
            printf("the mode of _exit!\nThere is a message in the following:\n");
            printf("Hello world!");
            _exit(0);
        }
    }
    return 0;
}
