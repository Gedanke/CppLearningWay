#include <stdio.h>
#include <string.h>

int main(void)
{
    char dst[100] = {0};
    int a = 10;
    char src[] = "hello world";
    printf("a = %d, src = %s", a, src);
    printf("\n");

    int len = sprintf(dst, "a = %d, src = %s", a, src);
    printf("dst = \" %s\"\n", dst);
    printf("len = %d\n", len);

    /*
        a = 10, src = hello world
        dst = " a = 10, src = hello world"
        len = 25
    */

    return 0;
}