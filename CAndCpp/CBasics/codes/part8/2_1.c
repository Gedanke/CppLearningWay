#include <stdio.h>
#include <stdlib.h>

int e;
static int f;
int g = 10;
static int h = 10;

int main()
{
    int a;
    int b = 10;
    static int c;
    static int d = 10;
    char *i = "test";
    char *k = NULL;

    printf("&a\t %p\t // 局部未初始化变量\n", &a);
    printf("&b\t %p\t // 局部初始化变量\n", &b);

    printf("&c\t %p\t // 静态局部未初始化变量\n", &c);
    printf("&d\t %p\t // 静态局部初始化变量\n", &d);

    printf("&e\t %p\t // 全局未初始化变量\n", &e);
    printf("&f\t %p\t // 全局静态未初始化变量\n", &f);

    printf("&g\t %p\t // 全局初始化变量\n", &g);
    printf("&h\t %p\t // 全局静态初始化变量\n", &h);

    printf("i\t %p\t // 只读数据(文字常量区)\n", i);

    k = (char *)malloc(10);
    printf("k\t %p\t // 动态分配的内存\n", k);

    /*
        &a       0x7ffcbf3eba70  // 局部未初始化变量
        &b       0x7ffcbf3eba74  // 局部初始化变量
        &c       0x563ead0d1024  // 静态局部未初始化变量
        &d       0x563ead0d1018  // 静态局部初始化变量
        &e       0x563ead0d1028  // 全局未初始化变量
        &f       0x563ead0d1020  // 全局静态未初始化变量
        &g       0x563ead0d1010  // 全局初始化变量
        &h       0x563ead0d1014  // 全局静态初始化变量
        i        0x563ead0cf008  // 只读数据(文字常量区)
        k        0x563eadb416b0  // 动态分配的内存
    */

    return 0;
}
