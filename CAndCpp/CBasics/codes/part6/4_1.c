#include <stdio.h>

int max(int x, int y); // 函数的声明，分号不能省略
// int max(int, int); // 另一种方式

int main()
{
    int a = 10, b = 25, num_max = 0;
    num_max = max(a, b); // 函数的调用

    printf("num_max = %d\n", num_max);

    // num_max = 25

    return 0;
}

// 函数的定义
int max(int x, int y)
{
    return x > y ? x : y;
}
