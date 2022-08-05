#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *func()
{
    static char arr[] = "hello world!"; // 在静态区存储是可读可写
    arr[2] = 'c';
    char *p = "hello world!"; // 全局/静态区-字符串常量区
    // p[2] = 'c'; // 只读，不可修改
    printf("%p\n", arr);
    printf("%p\n", p);
    printf("%s\n", arr);
    return arr;
}

void test()
{
    char *p = func();
    printf("%s\n", p);
}

int main()
{
    test();

    /*
        0x55d671ec6010
        0x55d671ec4004
        heclo world!
        heclo world!
    */

    return 0;
}