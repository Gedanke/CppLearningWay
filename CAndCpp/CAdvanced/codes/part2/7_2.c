#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 打印数组
void print_array(int **arr, int r, int l)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < l; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

// 二级指针输入特性(由主调函数分配内存)
void test()
{
    int a[5] = {0};
    int n = 5;

    int **arr = (int **)malloc(sizeof(int *) * n);
    arr[0] = a;
    arr[1] = a;
    arr[2] = a;
    arr[3] = a;
    arr[4] = a;

    print_array(arr, n, sizeof(a) / sizeof(a[0]));

    free(arr);
    arr = NULL;
}

int main()
{
    test();

    /*
        0 0 0 0 0
        0 0 0 0 0
        0 0 0 0 0
        0 0 0 0 0
        0 0 0 0 0
    */

    return 0;
}