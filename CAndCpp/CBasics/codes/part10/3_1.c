#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "w");
    
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

    // this is a test for fputc

    return 0;
}
