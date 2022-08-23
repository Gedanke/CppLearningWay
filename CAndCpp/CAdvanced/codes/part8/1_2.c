#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_func(int a, int b)
{
    printf("ret: %d\n", a + b);
    return 0;
}

// 先定义函数类型，通过类型定义指针
void test1()
{
    typedef int(FUNC_TYPE)(int, int);
    FUNC_TYPE *f = my_func;
    // 调用
    (*f)(10, 20);
    f(10, 20);
}

// 定义函数指针类型
void test2()
{
    typedef int (*FUNC_POINTER)(int, int);
    FUNC_POINTER f = my_func;
    // 调用
    (*f)(10, 20);
    f(10, 20);
}

// 直接定义函数指针变量
void test3()
{
    int (*f)(int, int) = my_func;
    // 调用
    (*f)(10, 20);
    f(10, 20);
}

int main()
{
    test1();
    test2();
    test3();

    /*
        ret: 30
        ret: 30
        ret: 30
        ret: 30
        ret: 30
        ret: 30
    */

    return 0;
}