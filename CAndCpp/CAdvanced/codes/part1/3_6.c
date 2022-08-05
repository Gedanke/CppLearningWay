#include <stdio.h>

int func(int a, int b)
{
    int t_a = a;
    int t_b = b;
    return t_a + t_b;
}

int main()
{
    int ret = 0;
    ret = func(10, 20);
    printf("%d\n", ret);

    // 30

    return 0;
}
