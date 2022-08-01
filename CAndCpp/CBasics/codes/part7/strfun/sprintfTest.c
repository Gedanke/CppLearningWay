#include <stdio.h>
#include <string.h>

int main(void)
{
    char dst[100] = {0};
    // char *dest = "123456789123456789123456789"; // Segmentation fault
    char dest[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int a = 10;
    char src[] = "hello world";
    printf("a = %d, src = %s", a, src);
    printf("\n");

    int len = sprintf(dst, "a = %d, src = %s", a, src);
    printf("dst = \" %s\"\n", dst);
    printf("len = %d\n", len);

    int l = sprintf(dest, "a = %d, src = %s", a, src);
    printf("dest = \" %s\"\n", dest);
    printf("len = %d\n", l);

    /*
        a = 10, src = hello world
        dst = " a = 10, src = hello world"
        len = 25
        dest = " a = 10, src = hello world"
        len = 25
    */

    return 0;
}