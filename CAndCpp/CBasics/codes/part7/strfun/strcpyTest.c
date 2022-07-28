#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest[20];
    char src[] = "hello world";

    // \0 也拷贝过来了
    strncpy(dest, src, sizeof(src));
    printf("%s\n", dest);

    dest[5] = '\0';
    printf("%s\n", dest);

    /*
        hello world
        hello
    */

    return 0;
}
