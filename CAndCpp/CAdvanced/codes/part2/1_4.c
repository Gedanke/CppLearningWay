#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 解引用
void test()
{
    // 定义指针
    int *p = NULL;
    // 指针指向谁，就把谁的地址赋给指针
    int a = 10;
    p = &a;
    *p = 20; // * 在左边当左值，必须确保内存可写
    // * 放右面，从内存中读值
    int b = *p;
    // 必须确保内存可写
    char *str = "hello world!";
    // *str = 'm';

    printf("a: %d\n", a);
    printf("*p: %d\n", *p);
    printf("b: %d\n", b);
    printf("str: %s\n", str);
}

int main()
{
    test();

    /*
        a: 20
        *p: 20
        b: 20
        str: hello world!
    */

    return 0;
}