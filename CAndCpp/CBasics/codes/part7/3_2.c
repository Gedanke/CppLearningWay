#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;
    int n = sizeof(a) / sizeof(a[0]);

    for (i = 0; i < n; i++)
    {
        // printf("%d, ", a[i]);
        printf("%d, ", *(a + i));
    }
    printf("\n");

    int *p = a; // 定义一个指针变量保存 a 的地址
    for (i = 0; i < n; i++)
    {
        p[i] = 2 * i;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d, ", *(p + i));
    }
    printf("\n");

    /*
        1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 2, 4, 6, 8, 10, 12, 14, 16,
    */

    return 0;
}