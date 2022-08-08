#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    char *p = NULL;
    p = (char *)malloc(50);
    strcpy(p, "abcdef");

    if (p != NULL)
    {
        // free() 函数的功能只是告诉系统 p 指向的内存可以回收了
        // 就是说，p 指向的内存使用权交还给系统
        // 但是，p 的值还是原来的值(野指针)，p 还是指向原来的内存
        free(p);
    }

    if (p != NULL)
    {
        free(p);
    }
}

int main()
{
    test();

    /*
        free(): double free detected in tcache 2
        Aborted
    */

    return 0;
}