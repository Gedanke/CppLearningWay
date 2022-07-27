#include <stdio.h>

// 函数的定义
void test(int a, int b)
{
    printf("%d, %d\n", a, b);
}

int main()
{
    int p = 10, q = 20;
    test(p, q); // 函数的调用

    // 10, 20

    return 0;
}
