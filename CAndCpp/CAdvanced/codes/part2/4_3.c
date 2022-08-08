#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *str)
{
    if (str == NULL)
    {
        return;
    }

    int begin = 0;
    int end = strlen(str) - 1;

    while (begin < end)
    {
        // 交换两个字符元素
        char temp = str[begin];
        str[begin] = str[end];
        str[end] = temp;

        begin++;
        end--;
    }
}

void test()
{
    char str[] = "abcdefghijklmn";
    printf("str: %s\n", str);
    reverse_string(str);
    printf("str: %s\n", str);
}

int main()
{
    test();

    /*
        str: abcdefghijklmn
        str: nmlkjihgfedcba
    */

    return 0;
}