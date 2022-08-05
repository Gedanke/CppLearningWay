#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int v1 = 10;        // 全局/静态区
const int v2 = 20;  // 常量，一旦初始化，不可修改
static int v3 = 20; // 全局/静态区
char *p1;           // 全局/静态区，编译器默认初始化为 NULL

void test()
{
    static int v4 = 20; // 全局/静态区
}

int main()
{
    test();

    /*
     */

    return 0;
}