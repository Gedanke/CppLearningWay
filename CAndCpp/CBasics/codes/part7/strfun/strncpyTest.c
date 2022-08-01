#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest[20];
    char dest2[20];

    char src[] = "hello world";

    // \0 也拷贝过来了
    strncpy(dest, src, sizeof(src));
    printf("%s\n", dest);

    dest[5] = '\0';
    printf("%s\n", dest);


    strncpy(dest2, src, sizeof(src) - 2);
    printf("%s\n", dest2);

    dest2[sizeof(src) - 2] = '\0';
    printf("%s\n", dest2);

    /*
        hello world
        hello
        hello worl��V
        hello worl
    */

    return 0;
}