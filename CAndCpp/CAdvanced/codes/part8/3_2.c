#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(int a)
{
    if (a == 1)
    {
        printf("a = %d\n", a);
        return; // 中断函数很重要
    }

    fun(a - 1);
    printf("a = %d\n", a);
}

int main()
{
    fun(4);
    printf("main\n");

    /*
        a = 1
        a = 2
        a = 3
        a = 4
        main
    */

    return 0;
}