#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 拷贝方法1
void copy_string1(char *dest, char *source)
{
    for (int i = 0; source[i] != '\0'; i++)
    {
        dest[i] = source[i];
    }
}

// 拷贝方法2
void copy_string2(char *dest, char *source)
{
    while (*source != '\0' /* *source != 0 */)
    {
        *dest = *source;
        source++;
        dest++;
    }
}

// 拷贝方法3
void copy_string3(char *dest, char *source)
{
    // 判断 *dest 是否为 0，0 则退出循环
    while (*dest++ = *source++)
    {
    }
}

int main()
{
    char *source = "copy_string";
    char dest1[20] = {0};
    char dest2[20] = {0};
    char dest3[20] = {0};

    copy_string1(dest1, source);
    copy_string1(dest2, source);
    copy_string1(dest3, source);

    printf("dest1: %s\n", dest1);
    printf("dest2: %s\n", dest2);
    printf("dest3: %s\n", dest3);

    /*
        dest1: copy_string
        dest2: copy_string
        dest3: copy_string
    */

    return 0;
}