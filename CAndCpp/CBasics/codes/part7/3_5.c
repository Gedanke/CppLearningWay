#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;
    int n = sizeof(a) / sizeof(a[0]);

    int *p = a + n - 1;
    for (i = 0; i < n; i++)
    {
        printf("%d, ", *p);
        p--;
    }
    printf("\n");

    int arr[] = {1, 2, 3, 4};
    int *p1 = arr;
    int *p2 = &arr;

    printf("%p\n", p1);
    printf("%p\n", p2);

    printf("%p\n", arr);
    printf("%p\n", &arr);

    printf("%p\n", p1 + 1);
    printf("%p\n", p2 + 1);

    printf("%p\n", arr);
    printf("%p\n", &arr + 1);

    /*
        main.c: In function ‘main’:
        main.c:19:15: warning: initialization of ‘int *’ from incompatible pointer type ‘int (*)[4]’ [-Wincompatible-pointer-types]
        19 |     int *p2 = &arr;
            |               ^
        9, 8, 7, 6, 5, 4, 3, 2, 1,
        0x7ffec5a70110
        0x7ffec5a70110
        0x7ffec5a70110
        0x7ffec5a70110
        0x7ffec5a70114
        0x7ffec5a70114
        0x7ffec5a70110
        0x7ffec5a70120
    */

    return 0;
}
