#include <stdio.h>

int main()
{
    int a;
    int *p = &a;
    printf("%p\n", p);
    p += 2; // 移动了 2 个 int
    printf("%p\n", p);

    char b = 0;
    char *p1 = &b;
    printf("%p\n", p1);
    p1 += 2; // 移动了 2 个 char
    printf("%p\n", p1);

    /*
        0x7fffc3fe8044
        0x7fffc3fe804c
        0x7fffc3fe8043
        0x7fffc3fe8045
    */

    return 0;
}
