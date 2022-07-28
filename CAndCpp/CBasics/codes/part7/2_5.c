#include <stdio.h>

int main()
{
    void *p = NULL;

    int a = 10;
    p = (void *)&a; // 指向变量时，最好转换为 void *

    // 使用指针变量指向的内存时，转换为 int *
    *((int *)p) = 11;
    printf("a = %d\n", a);

    /*
        a = 11
    */

    return 0;
}
