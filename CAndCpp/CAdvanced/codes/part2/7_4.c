#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 分配内存
void allocate_memory(char ***p, int n)
{
    if (n < 0)
    {
        return;
    }

    char **temp = (char **)malloc(sizeof(char *) * n);
    if (temp == NULL)
    {
        return;
    }

    // 分别给每一个指针 malloc 分配内存
    for (int i = 0; i < n; i++)
    {
        temp[i] = malloc(sizeof(char) * 30);
        sprintf(temp[i], "%2d_hello world!", i + 1);
    }

    *p = temp;
}

// 打印数组
void array_print(char **arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%s\n", arr[i]);
    }
}

// 释放内存
void free_memory(char ***buf, int len)
{
    if (buf == NULL)
    {
        return;
    }

    char **temp = *buf;

    for (int i = 0; i < len; i++)
    {
        free(temp[i]);
        temp[i] = NULL;
    }

    free(temp);
}

void test()
{
    int n = 10;
    char **p = NULL;
    allocate_memory(&p, n);
    // 打印数组
    array_print(p, n);
    // 释放内存
    free_memory(&p, n);
}

int main()
{
    test();

    /*
         1_hello world!
         2_hello world!
         3_hello world!
         4_hello world!
         5_hello world!
         6_hello world!
         7_hello world!
         8_hello world!
         9_hello world!
        10_hello world!
    */

    return 0;
}