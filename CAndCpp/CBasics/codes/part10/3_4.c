#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "rb");

    char buf[100] = {0};

    while (!feof(fp)) // 文件没有结束
    {
        memset(buf, 0, sizeof(buf));
        char *p = fgets(buf, sizeof(buf), fp);
        if (p != NULL)
        {
            printf("buf = %s", buf);
        }
    }

    /*
        buf = 123456
        buf = bbbbbbbbbb
        buf = ccccccccccc
    */

    return 0;
}