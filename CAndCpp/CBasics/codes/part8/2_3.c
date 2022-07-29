#include <stdio.h>
#include <string.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int flag = memcmp(a, b, sizeof(a));
    printf("flag = %d\n", flag);

    /*
        flag = 0
    */

    return 0;
}
