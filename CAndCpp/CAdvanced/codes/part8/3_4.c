#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse1(char *str)
{
    if (str == NULL)
    {
        return -1;
    }

    if (*str == '\0') // 函数递归调用结束条件
    {
        return 0;
    }

    reverse1(str + 1);
    printf("%c", *str);

    return 0;
}

// 全局变量
char buf[1024] = {0};

int reverse2(char *str)
{
    if (str == NULL)
    {
        return -1;
    }

    if (*str == '\0') // 函数递归调用结束条件
    {
        return 0;
    }

    reverse2(str + 1);
    strncat(buf, str, 1);

    return 0;
}

int reverse3(char *str, char *dst)
{
    if (str == NULL || dst == NULL)
    {
        return -1;
    }

    if (*str == '\0') // 函数递归调用结束条件
    {
        return 0;
    }

    reverse3(str + 1, dst);
    strncat(dst, str, 1);

    return 0;
}

int main()
{
    char *str = "abcdefg";
    char dst[10] = {0};

    printf("%s\n", str);
    reverse1(str);
    printf("\n");
    printf("%s\n", str);

    printf("----------\n");

    printf("%s\n", str);
    reverse2(str);
    printf("%s\n", str);
    printf("%s\n", buf);

    printf("----------\n");

    printf("%s\n", str);
    reverse3(str, dst);
    printf("%s\n", str);
    printf("%s\n", dst);

    /*
        abcdefg
        gfedcba
        abcdefg
        ----------
        abcdefg
        abcdefg
        gfedcba
        ----------
        abcdefg
        abcdefg
        gfedcba
    */

    return 0;
}