#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "ddda123abcd";
    char *p = strchr(src, 'a');
    printf("p = %s\n", p);

    /*
        p = a123abcd
    */

    return 0;
}