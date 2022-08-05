#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *func()
{
    char *str = malloc(100);
    strcpy(str, "hello world!");
    printf("%s\n", str);
    return str;
}

void test1()
{
    char *p = NULL;
    p = func();
    printf("%s\n", p);
}

void allocateSpace(char *p)
{
    p = malloc(100);
    // p 变量存储的地址发生改变
    strcpy(p, "hello world!");
    printf("%s\n", p);
}

void test2()
{
    char buf[] = "char";
    char *p = buf;

    // char *p = NULL; // Segmentation fault
    allocateSpace(p);

    printf("%s\n", p);
}

void fun(int *a)
{
    printf("%p\n", a);
    printf("%d\n", *a);

    a = (int *)malloc(sizeof(int));
    *a = 1;

    printf("%p\n", a);
    printf("%d\n", *a);
}

void test3()
{
    int *a;
    int tp = 10;
    a = &tp;

    printf("%p\n", a);
    printf("%d\n", *a);

    fun(a);

    printf("%p\n", a);
    printf("%d\n", *a);

    /*
        0x7ffc7919143c
        10
        0x7ffc7919143c
        10
        0x7ffc7919143c
        1
        0x7ffc7919143c
        1
    */

    // 取消 test3 中的注释

    /*
         0x7ffd1577a93c
         10
         0x7ffd1577a93c
         10
         0x55a01fff26b0
         1
         0x7ffd1577a93c
         10
    */
}

int main()
{
    test1();

    /*
        hello world!
        hello world!
    */

    test2();

    // test3();

    /*
        hello world!
        char
    */

    return 0;
}