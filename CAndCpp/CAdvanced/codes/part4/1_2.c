#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[] = {5, 3, 6, 8, 2, 9};
    int *p = arr + 2;
    printf("*p = %d\n", *p);
    printf("*p = %d\n", p[-1]);

    /*
        *p = 6
        *p = 3
    */

    return 0;
}