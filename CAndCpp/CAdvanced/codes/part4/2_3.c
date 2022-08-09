#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 数组做函数函数，退化为指针
void array_sort(char **arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = len - 1; j > i; j--)
        {
            // 比较两个字符串
            if (strcmp(arr[j - 1], arr[j]) > 0)
            {
                char *temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 打印数组
void array_print(char **arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%s\n", arr[i]);
    }
}

void test()
{
    // 主调函数分配内存
    // 指针数组
    char *p[] = {"bbb", "aaa", "ccc", "eee", "ddd"};
    // char** p = {"aaa", "bbb", "ccc", "ddd", "eee"}; // 错误
    int len = sizeof(p) / sizeof(char *);
    // 打印数组
    array_print(p, len);
    // 对字符串进行排序
    array_sort(p, len);
    printf("----------------\n");
    // 打印数组
    array_print(p, len);
}

int main()
{
    test();

    /*
        bbb
        aaa
        ccc
        eee
        ddd
        ----------------
        aaa
        bbb
        ccc
        ddd
        eee
    */

    return 0;
}