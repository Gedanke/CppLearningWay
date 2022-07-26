#include <stdio.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 定义一个数组，同时初始化所有成员变量

    printf("a = %p\n", a);
    printf("&a[0] = %p\n", &a[0]);

    int n = sizeof(a);     // 数组占用内存的大小，10 个 int 类型，10 * 4  = 40
    int n0 = sizeof(a[0]); // 数组第 0 个元素占用内存大小，第 0 个元素为 int，4

    int i = 0;
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    /*
        a = 0x7ffc7e9bc340
        &a[0] = 0x7ffc7e9bc340
        1 2 3 4 5 6 7 8 9 10
    */

    return 0;
}
