#include <stdio.h>

int main()
{
    int a[] = {1, -2, 3, -4, 5, -6, 7, -8, -9, 10}; // 定义一个数组，同时初始化所有成员变量

    int i = 0;
    int max = a[0];
    for (i = 1; i < sizeof(a) / sizeof(a[0]); i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    printf("数组中最大值为：%d\n", max);

    // 数组中最大值为：10

    return 0;
}
