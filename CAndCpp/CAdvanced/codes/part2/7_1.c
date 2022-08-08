#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 被调函数，由参数 n 确定分配多少个元素内存
void allocate_space(int **arr, int n)
{
    // 堆上分配 n 个 int 类型元素内存
    int *temp = (int *)malloc(sizeof(int) * n);
    if (NULL == temp)
    {
        return;
    }
    // 给内存初始化值
    int *pTemp = temp;
    for (int i = 0; i < n; i++)
    {
        // temp[i] = i + 100;
        *pTemp = i + 100;
        pTemp++;
    }
    // 指针间接赋值
    *arr = temp;
}

// 打印数组
void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 二级指针输出特性(由被调函数分配内存)
void test()
{
    int *arr = NULL;
    int n = 10;
    // 给 arr 指针间接赋值
    allocate_space(&arr, n);
    // 输出 arr 指向数组的内存
    print_array(arr, n);
    // 释放 arr 所指向内存空间的值
    if (arr != NULL)
    {
        free(arr);
        arr = NULL;
    }
}

int main()
{
    test();

    /*
        100 101 102 103 104 105 106 107 108 109
    */

    return 0;
}