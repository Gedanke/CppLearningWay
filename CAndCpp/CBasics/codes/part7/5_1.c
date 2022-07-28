#include <stdio.h>

void swap1(int x, int y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
    printf("x = %d, y = %d\n", x, y);
}

void swap2(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int a = 3;
    int b = 5;
    printf("a = %d, b = %d\n", a, b);

    swap1(a, b); // 值传递
    printf("a = %d, b = %d\n", a, b);

    a = 3;
    b = 5;
    printf("a = %d, b = %d\n", a, b);
    swap2(&a, &b); // 地址传递
    printf("a = %d, b = %d\n", a, b);

    /*
        a = 3, b = 5
        x = 5, y = 3
        a = 3, b = 5
        a = 3, b = 5
        a = 5, b = 3
    */

    return 0;
}
