#include <stdio.h>

// 求两数的最大值
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    // 操作 1
    // ...
    int a1 = 10, b1 = 20, c1 = 0;
    c1 = max(a1, b1); // 调用 max()

    printf("max(a1, b1) = %d\n", c1);

    // 操作 2
    // ...
    int a2 = 11, b2 = 21, c2 = 0;
    c2 = max(a2, b2); // 调用 max()

    printf("max(a2, b2) = %d\n", c2);

    /*
        max(a1, b1) = 20
        max(a2, b2) = 21
    */

    return 0;
}
