#include <stdio.h>

// sizeof 基本用法
void test1()
{
    int a = 10;
    printf("len: %lu\n", sizeof(a));
    printf("len: %lu\n", sizeof(int));
    printf("len: %lu\n", sizeof a);
}

// sizeof 结果类型
void test2()
{
    unsigned int a = 10;
    if (a - 11 < 0)
    {
        printf("结果小于 0\n");
    }
    else
    {
        printf("结果大于 0\n");
    }
    int b = 5;
    if (sizeof(b) - 10 < 0)
    {
        printf("结果小于 0\n");
    }
    else
    {
        printf("结果大于 0\n");
    }
}

// sizeof 碰到数组
void TestArray(int arr[])
{
    printf("TestArray arr size: %lu\n", sizeof(arr));
}
void test3()
{
    int arr[] = {10, 20, 30, 40, 50};
    printf("array size: %lu\n", sizeof(arr));
    printf("array length: %lu\n", sizeof(arr) / sizeof(arr[0]));

    // 数组名在某些情况下等价于指针
    int *pArr = arr;
    printf("arr[2] value: %d\n", pArr[2]);
    printf("array size: %lu\n", sizeof(pArr));

    // 数组做函数函数参数，将退化为指针，在函数内部不再返回数组大小
    TestArray(arr);
}

int main()
{
    test1();
    test2();
    test3();

    /*
        main.c: In function ‘TestArray’:
        main.c:38:47: warning: ‘sizeof’ on array function parameter ‘arr’ will return size of ‘int *’ [-Wsizeof-array-argument]
        38 |     printf("TestArray arr size: %lu\n", sizeof(arr));
            |                                               ^
        main.c:36:20: note: declared here
        36 | void TestArray(int arr[])
            |                ~~~~^~~~~
        len: 4
        len: 4
        len: 4
        结果大于 0
        结果大于 0
        array size: 20
        array length: 5
        arr[2] value: 30
        array size: 8
        TestArray arr size: 8
    */

    return 0;
}