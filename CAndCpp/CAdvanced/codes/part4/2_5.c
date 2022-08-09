#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 二维数组的线性存储
void test()
{
    int arr[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int arr2[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr2) / sizeof(int);

    // 如何证明二维数组是线性的
    // 通过将数组首地址指针转成 int* 类型，那么步长就变成了 8，就可以遍历整个数组
    int *p = (int *)arr;
    for (int i = 0; i < len; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    PrintArray((int *)arr, len);
    PrintArray((int *)arr2, len);
}

int main()
{
    test();

    /*
        1 2 3 4 5 6 7 8 9
        1 2 3 4 5 6 7 8 9
        1 2 3 4 5 6 7 8 9
    */

    return 0;
}