#include <stdio.h>

int *fun()
{
    int a = 10;
    return &a; // 函数调用完毕，a 释放
}

int main(int argc, char *argv[])
{
    int *p = NULL;
    p = fun();
    *p = 100; // 操作野指针指向的内存，err

    /*
        main.c: In function ‘fun’:
        main.c:6:12: warning: function returns address of local variable [-Wreturn-local-addr]
            6 |     return &a; // 函数调用完毕，a 释放
            |            ^~
        Segmentation fault
    */

    return 0;
}
