#include <stdio.h>

/* 赋值 */
static int value_assignment(int input)
{
    int ret = 0;

    asm volatile(
        /* ret = input */
        "movl %1, %0\n" /* 通过占位符指定交互的变量 ： %0:ret %1:input*/
        : "=r"(ret)
        : "r"(input));

    return ret;
}

int main()
{
    int input = 1;
    int ret = value_assignment(input);

    printf("input = %d\n", input);
    printf("ret = %d\n", ret);

    /*
        input = 1
        ret = 1
    */

    return 0;
}