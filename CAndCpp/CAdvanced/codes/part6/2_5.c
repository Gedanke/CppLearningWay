#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    // 写文件
    FILE *fp_write = NULL;
    // 写方式打开文件
    fp_write = fopen("./mydata.txt", "w");
    if (fp_write == NULL)
    {
        perror("fopen:");
        return;
    }

    fprintf(fp_write, "hello world:%d!", 10);

    // 关闭文件
    fclose(fp_write);
    fp_write = NULL;

    // 读文件
    FILE *fp_read = NULL;
    fp_read = fopen("./mydata.txt", "rb");
    if (fp_read == NULL)
    {
        perror("fopen:");
        return;
    }

    char temps[1024] = {0};
    while (!feof(fp_read))
    {
        fscanf(fp_read, "%s", temps);
        printf("%s", temps);
    }
    printf("\n");

    fclose(fp_read);
    fp_read = NULL;
}

int main()
{
    test();

    /*
        helloworld:10!
    */

    return 0;
}