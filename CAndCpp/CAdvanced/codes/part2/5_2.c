#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    char *p = (char *)malloc(50);
    char buf[] = "abcdef";
    int n = strlen(buf);
    int i = 0;

    for (i = 0; i < n; i++)
    {
        *p = buf[i];
        p++; // 修改原指针指向
    }

    // 重新移动回来，可以正常释放
    // for (i = 0; i < n; i++)
    // {
    //     p--;
    // }

    free(p);
}

int main()
{
    test();

    /*
        free(): invalid pointer
        Aborted
    */

    return 0;
}