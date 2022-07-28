#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;
    int n = sizeof(a) / sizeof(a[0]);

    int *p = a;
    for (i = 0; i < n; i++)
    {
        printf("%d, ", *p);
        p++;
    }
    printf("\n");

    /*
        1, 2, 3, 4, 5, 6, 7, 8, 9,
    */

    return 0;
}