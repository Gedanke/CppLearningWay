#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *fileName = NULL;
char result[100];

// 获取表达式的值
void getResult(char *expression);

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("参数数量不足，请在 ./xxx 后加入文件路径\n");
        return 0;
    }
    fileName = argv[1];

    // 读取文件，获取表达式并将计算结果写入到 array 中
    FILE *f1 = fopen(fileName, "r");
    char array[1024] = {0};
    char buff[100];

    while (!feof(f1))
    {
        memset(buff, 0, sizeof(buff));
        char *p = fgets(buff, sizeof(buff), f1);
        if (p != NULL)
        {
            getResult(p);
            strcat(array, result);
            printf("%s", result);
        }
    }
    fclose(f1);

    // 打开文件，写入动态数组中的内容
    FILE *f2 = fopen(fileName, "w");
    fputs(array, f2);
    fclose(f2);

    /*
     */

    return 0;
}

// 获取表达式的值
void getResult(char *expression)
{
    memset(result, 0, sizeof(result));
    int num1, num2;
    char ch;
    int res = 0;

    sscanf(expression, "%d%c%d=\n", &num1, &ch, &num2);

    if (ch == '+')
    {
        res = num1 + num2;
    }
    else if (ch == '-')
    {
        res = num1 - num2;
    }
    else if (ch == '*')
    {
        res = num1 * num2;
    }
    else
    {
        res = num1 / num2;
    }

    sprintf(result, "%d%c%d=%d\n", num1, ch, num2, res);
}