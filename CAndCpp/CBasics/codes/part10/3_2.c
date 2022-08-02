#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "wb");

    char buf[] = "this is a test for fputc";
    int i = 0;
    int n = strlen(buf);
    for (i = 0; i < n; i++)
    {
        // 往文件 fp 写入字符 buf[i]
        int ch = fputc(buf[i], fp);
        printf("%c", ch);
    }
    printf("\n");

    fclose(fp);

    int sign = 0;
    char ch;
    FILE *f = NULL;
    f = fopen("./test", "rb");

    if (sign)
    {
        while ((ch = fgetc(f)) != EOF)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
    else
    {
        while (1)
        {
            ch = fgetc(f);

            if (!feof(f))
            {
                printf("%c", ch);
            }
            else
            {
                break;
            }
        }
        printf("\n");
    }
    fclose(f);

    /*
        this is a test for fputc
        this is a test for fputc
    */

    return 0;
}