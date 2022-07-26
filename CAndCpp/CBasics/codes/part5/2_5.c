#include <stdio.h>

int main()
{
    int a[] = {1, -2, 3, -4, 5, -6, 7, -8, -9, 10}; // 定义一个数组，同时初始化所有成员变量

    int i = 0;
    int j = 0;
    int n = sizeof(a) / sizeof(a[0]);
    int tmp;

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    // 1、流程
    // 2、试数
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++) // 内循环的目的是比较相邻的元素，把大的放到后面
        {
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    /*
        1 -2 3 -4 5 -6 7 -8 -9 10
        -9 -8 -6 -4 -2 1 3 5 7 10
    */

    return 0;
}
