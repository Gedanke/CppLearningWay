#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *fileName = NULL;

// 获取表达式的值
int getResult(char *expression);

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("参数数量不足，请在 ./xxx 后加入文件路径\n");
        return 0;
    }
    fileName = argv[1];

    // 第一次读取文件，获取表达式数目
    int num = 0;
    FILE *f1 = fopen(fileName, "r");
    char buff[100] = {0};

    while (!feof(f1))
    {
        memset(buff, 0, sizeof(buff));
        char *p = fgets(buff, sizeof(buff), f1);
        if (p != NULL)
        {
            num++;
        }
    }
    fclose(f1);
    // printf("%d\n", num);

    char **array = (char **)malloc(sizeof(char *) * num);

    // 第一次读取文件，获取表达式并将计算结果写入到 array 中
    int idx = 0;
    FILE *f2 = fopen(fileName, "r");

    while (!feof(f2))
    {
        memset(buff, 0, sizeof(buff));
        char *p = fgets(buff, sizeof(buff), f2);
        if (p != NULL)
        {
            // printf("%s", p);
            // printf("%d\n", getResult(p));
            // 得到结果，将结果添加到 buff 里面
            char res[50] = {0};
            // 结果字符串
            sprintf(res, "%d", getResult(p));
            char tmp[100] = {0};
            strncpy(tmp, p, strlen(p) - 1);
            strcat(tmp, res);
            strcat(tmp, "\n");

            array[idx] = (char *)malloc(sizeof(char) * 50);
            strcpy(array[idx], tmp);
            printf("%s", array[idx]);
            idx++;
        }
    }

    fclose(f2);

    // 第三次打开文件，写入动态数组中的内容
    FILE *f3 = fopen(fileName, "w");

    for (int i = 0; i < num; i++)
    {
        fputs(array[i], f3);
        free(array[i]);
    }

    free(array);
    fclose(f3);

    /*
     */

    return 0;
}

// 获取表达式的值
int getResult(char *expression)
{
    int res = 0;
    // 确定长度
    int len = strlen(expression);
    // 找四则运算，并确定其位置
    int idx = 0;
    int sign = -1;

    char num1[50] = {0};
    char num2[50] = {0};

    for (int i = 0; i < len - 1; i++)
    {
        if (expression[i] == '+')
        {
            idx = i;
            sign = 1;
        }
        else if (expression[i] == '-')
        {
            idx = i;
            sign = 2;
        }
        else if (expression[i] == '*')
        {
            idx = i;
            sign = 3;
        }
        else if (expression[i] == '/')
        {
            idx = i;
            sign = 4;
        }
        else
        {
            // 暂时未找到运算符
            if (sign == -1)
            {
                num1[i] = expression[i];
            }
            else
            {
                num2[i - idx - 1] = expression[i];
            }
        }
    }

    int n1 = atoi(num1);
    int n2 = atoi(num2);
    switch (sign)
    {
    case 1:
    {
        res = n1 + n2;
        break;
    }
    case 2:
    {
        res = n1 - n2;
        break;
    }
    case 3:
    {
        res = n1 * n2;
        break;
    }
    case 4:
    {
        res = n1 / n2;
        break;
    }
    default:
    {
        break;
    }
    };

    return res;
}