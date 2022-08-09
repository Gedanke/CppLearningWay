#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 方式一
void test1()
{
    // 先定义数组类型，再用数组类型定义数组指针
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 有 typedef 是定义类型，没有则是定义变量，下面代码定义了一个数组类型 ArrayType
    typedef int(ArrayType)[10];
    // int ArrayType[10]; // 定义一个数组，数组名为 ArrayType

    ArrayType myarr;        // 等价于 int myarr[10];
    ArrayType *pArr = &arr; // 定义了一个数组指针 pArr，并且指针指向数组 arr
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", (*pArr)[i]);
    }
    printf("\n");
}

// 方式二
void test2()
{
    int arr[10];
    // 定义数组指针类型
    typedef int(*ArrayType)[10];
    ArrayType pArr = &arr; // 定义了一个数组指针 pArr，并且指针指向数组 arr
    for (int i = 0; i < 10; i++)
    {
        (*pArr)[i] = i + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", (*pArr)[i]);
    }
    printf("\n");
}

// 方式三
void test3()
{
    int arr[10];
    int(*pArr)[10] = &arr;

    for (int i = 0; i < 10; i++)
    {
        (*pArr)[i] = i + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", (*pArr)[i]);
    }
    printf("\n");
}

int main()
{
    test1();
    test2();
    test3();

    /*
        1 2 3 4 5 6 7 8 9 10
        1 2 3 4 5 6 7 8 9 10
        1 2 3 4 5 6 7 8 9 10
    */

    return 0;
}