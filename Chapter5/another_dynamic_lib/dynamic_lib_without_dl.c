/***********************************************************/
//     File Name   : dynamic_lib_without_dl.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sun 19 Mar 2017 09:16:34 AM CST
/**********************************************************/

#include <stdio.h>
#include "test.h"

int main(int argc,char *argv[])
{
    int num1 = 1, num2 = 2;
    
    printf("the plus; %d + %d = %d\n", num1, num2, add(num1, num2));
    printf("the max between %d and %d is %d.\n", num1, num2, max(num1, num2));
    return 0;
}
