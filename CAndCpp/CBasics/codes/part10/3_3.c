#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "wb");

    char *buf[] = {"123456\n", "bbbbbbbbbb\n", "ccccccccccc\n"};
    int i = 0;
    int n = 3;
    for (i = 0; i < n; i++)
    {
        int len = fputs(buf[i], fp);
        printf("len = %d\n", len);
    }

    /*
        len = 1
        len = 1
        len = 1
    */

    return 0;
}
