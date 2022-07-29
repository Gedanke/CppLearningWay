#include <stdio.h>
#include <string.h>

int main()
{
    int a[10];

    memset(a, 0, sizeof(a));
    memset(a, 97, sizeof(a));
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%c ", a[i]);
    }
    printf("\n");

    /*
        a a a a a a a a a a
    */

    return 0;
}
