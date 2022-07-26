#include <stdio.h>

int main()
{
    int a = 1;
    do
    {
        a++;
        printf("a = %d\n", a);
    } while (a < 5);

    /*
        a = 2
        a = 3
        a = 4
        a = 5
    */

    return 0;
}
