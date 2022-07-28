#include <stdio.h>

void mystrcat(char *dest, const char *src)
{
    int len1 = 0;
    int len2 = 0;
    while (dest[len1])
    {
        len1++;
    }
    while (src[len2])
    {
        len2++;
    }

    int i;
    for (i = 0; i < len2; i++)
    {
        dest[len1 + i] = src[i];
    }
}

int main()
{
    char dst[100] = "hello mike";
    char src[] = "123456";

    mystrcat(dst, src);
    printf("dst = %s\n", dst);

    // dst = hello mike123456

    return 0;
}
