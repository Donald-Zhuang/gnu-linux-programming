/***********************************************************/
//     File Name   : main.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sat 18 Mar 2017 07:00:16 PM CST
/**********************************************************/

#include <stdio.h>
#include "test.h"

//extern int add(int, int);
//extern int max(int, int);

int main(int argc,char *argv[])
{
    int num1 = 1; 
    int num2 = 2;

    printf( "the plus: %d + %d = %d\n",num1, num2, add(num1, num2) );
    printf("the max of %d and %d is %d\n", num1, num2, max(num1, num2) );
    return 0;
}
