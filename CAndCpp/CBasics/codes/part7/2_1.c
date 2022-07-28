#include <stdio.h>

int main()
{
    int a = 0;
    char b = 100;
    printf("%p, %p\n", &a, &b); // 打印 a, b 的地址

    // int * 代表是一种数据类型，int * 指针类型，p 才是变量名
    // 定义了一个指针类型的变量，可以指向一个 int 类型变量的地址
    int *p;
    p = &a;             // 将 a 的地址赋值给变量 p，p 也是一个变量，值是一个内存地址编号
    printf("%d\n", *p); // p 指向了 a 的地址，*p 就是 a 的值

    char *p1 = &b;
    printf("%c\n", *p1); // *p1 指向了 b 的地址，*p1 就是 b 的值

    /*
        0x7ffc536fcee4, 0x7ffc536fcee3
        0
        d
    */

    return 0;
}
