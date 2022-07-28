#include <stdio.h>

int main()
{
    // 指针数组
    int *p[3];
    int a = 1;
    int b = 2;
    int c = 3;
    int i = 0;

    p[0] = &a;
    p[1] = &b;
    p[2] = &c;

    for (i = 0; i < sizeof(p) / sizeof(p[0]); i++)
    {
        printf("%d, ", *(p[i]));
    }
    printf("\n");

    // 1, 2, 3,

    return 0;
}
