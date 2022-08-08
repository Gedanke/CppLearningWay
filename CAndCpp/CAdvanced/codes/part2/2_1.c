#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func1()
{
    return 10;
}

void func2(int a)
{
    a = 100;
}

// 指针的意义_间接赋值
void test1()
{
    int a = 0;
    a = func1();
    printf("a = %d\n", a);

    // 为什么没有修改
    func2(a);
    printf("a = %d\n", a);
}

// 指针的间接赋值
void func3(int *a)
{
    *a = 100;
}

void test2()
{
    int a = 0;
    a = func1();
    printf("a = %d\n", a);

    // 修改
    func3(&a);
    printf("a = %d\n", a);
}

int main()
{
    test1();
    test2();

    /*
        a = 10
        a = 10
        a = 10
        a = 100
    */

    return 0;
}