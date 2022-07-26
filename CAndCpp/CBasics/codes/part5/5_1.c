#include <stdio.h>

int main()
{
    char c1[] = {'c', ' ', 'p', 'r', 'o', 'g'}; // 普通字符数组
    printf("c1 = %s\n", c1);                    // 乱码，因为没有 \0 结束符

    // 以 \0(\0 就是数字 0)结尾的字符数组是字符串
    char c2[] = {'c', ' ', 'p', 'r', 'o', 'g', '\0'};
    printf("c2 = %s\n", c2);

    // 字符串处理以 \0 (数字 0)作为结束符，后面的 'h', 'l', 'l', 'e', 'o' 不会输出
    char c3[] = {'c', ' ', 'p', 'r', 'o', 'g', '\0', 'h', 'l', 'l', 'e', 'o', '\0'};
    printf("c3 = %s\n", c3);

    /*
        c1 = c prog
        c2 = c prog
        c3 = c prog
    */

    return 0;
}
