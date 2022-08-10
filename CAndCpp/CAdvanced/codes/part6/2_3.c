#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    // 写文件
    FILE *fp_write = NULL;
    // 写方式打开文件
    fp_write = fopen("./mydata.txt", "w+");
    if (fp_write == NULL)
    {
        perror("fopen:");
        return;
    }

    char *buf[] = {
        "01 this is a test for pfutc!\n",
        "02 this is a test for pfutc!\n",
        "03 this is a test for pfutc!\n",
        "04 this is a test for pfutc!\n",
    };
    for (int i = 0; i < sizeof(buf) / sizeof(char *); i++)
    {
        fputs(buf[i], fp_write);
    }

    fclose(fp_write);

    // 读文件
    FILE *fp_read = NULL;
    fp_read = fopen("./mydata.txt", "r");
    if (fp_read == NULL)
    {
        perror("fopen:");
        return;
    }

    // 判断文件结尾
    while (!feof(fp_read))
    {
        char temp[1024] = {0};
        fgets(temp, 1024, fp_read);
        printf("%s", temp);
    }

    fclose(fp_read);
}

int main()
{
    test();

    /*
        01 this is a test for pfutc!
        02 this is a test for pfutc!
        03 this is a test for pfutc!
        04 this is a test for pfutc!
    */

    return 0;
}