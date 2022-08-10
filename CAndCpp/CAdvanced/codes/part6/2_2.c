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
        return;
    }

    char buf[] = "this is a test for pfutc!";
    for (int i = 0; i < strlen(buf); i++)
    {
        fputc(buf[i], fp_write);
    }

    fclose(fp_write);

    // 读文件
    FILE *fp_read = NULL;
    fp_read = fopen("./mydata.txt", "r");
    if (fp_read == NULL)
    {
        return;
    }

#if 0
	// 判断文件结尾 注意：多输出一个空格
	while (!feof(fp_read)){
		printf("%c",fgetc(fp_read));
	}
#else
    char ch;
    while ((ch = fgetc(fp_read)) != EOF)
    {
        printf("%c", ch);
    }
#endif
    printf("\n");
}

int main()
{
    test();

    /*
        this is a test for pfutc!
    */

    return 0;
}