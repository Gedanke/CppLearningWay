#include <stdio.h>

// 函数的定义
void test(int a, int b)
{
    printf("%d, %d\n", a, b);
}

int main()
{
    // 函数的调用
    int p = 10, q = 20;
    test(p, q);        // right
    test(11, 30 - 10); // right
    // test(int a, int b); // error 不应该在圆括号里定义变量，应输入表达式

    /*
        10, 20
        11, 20
    */

    return 0;
}