#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest[20] = "123456789012345678";
    printf("%s\n", dest);

    char src[] = "hello world";
    strcpy(dest, src);

    printf("%s\n", dest);

    for (int i = 0; i < sizeof(dest) / sizeof(char); i++)
    {
        printf("%c\n", dest[i]);
    }
    printf("\n");

    /*
        123456789012345678
        hello world
        h
        e
        l
        l
        o

        w
        o
        r
        l
        d

        3
        4
        5
        6
        7
        8



    */

    return 0;
}