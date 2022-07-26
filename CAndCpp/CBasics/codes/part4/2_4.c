#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    int c;

    if (a > b)
    {
        c = a;
    }
    else
    {
        c = b;
    }
    printf("c1 = %d\n", c);

    a = 1;
    b = 2;
    c = (a > b ? a : b);
    printf("c2 = %d\n", c);

    /*
        c1 = 20
        c2 = 2
    */

    return 0;
}
