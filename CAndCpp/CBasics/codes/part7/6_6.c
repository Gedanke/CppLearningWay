#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *p = "11abcd111122abcd333abcd3322abcd3333322qqq";
    int n = 0;

    do
    {
        p = strstr(p, "abcd");
        if (p != NULL)
        {
            n++; // 累计个数

            // 重新设置查找的起点
            p = p + strlen("abcd");
        }
        else // 如果没有匹配的字符串，跳出循环
        {
            break;
        }
    } while (*p != 0); // 如果没有到结尾

    printf("n = %d\n", n);

    // n = 4

    return 0;
}
