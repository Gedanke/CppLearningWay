#include <stdio.h>

int main()
{
    int a = 100;
    int *p;

    p = a; // 把 a 的值赋值给指针变量 p，p 为野指针，ok，不会有问题，但没有意义

    p = 0x12345678; // 给指针变量 p 赋值，p 为野指针，ok，不会有问题，但没有意义

    *p = 1000; // 操作野指针指向未知区域，内存出问题，err

    /*
        main.c: In function ‘main’:
        main.c:8:7: warning: assignment to ‘int *’ from ‘int’ makes pointer from integer without a cast [-Wint-conversion]
            8 |     p = a; // 把 a 的值赋值给指针变量 p，p 为野指针，ok，不会有问题，但没有意义
            |       ^
        main.c:10:7: warning: assignment to ‘int *’ from ‘int’ makes pointer from integer without a cast [-Wint-conversion]
        10 |     p = 0x12345678; // 给指针变量 p 赋值，p 为野指针，ok，不会有问题，但没有意义
            |       ^
        Segmentation fault
    */

    return 0;
}
