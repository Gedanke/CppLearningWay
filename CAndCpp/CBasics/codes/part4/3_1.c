#include <stdio.h>

int main()
{
    int a = 20;
    while (a > 10)
    {
        scanf("%d", &a);
        printf("a = %d\n", a);
    }

    /*
        11
        a = 11
        10
        a = 10
    */

    return 0;
}