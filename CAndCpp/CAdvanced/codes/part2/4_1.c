#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 字符串基本操作
// 字符串是以 0 或者 \0 结尾的字符数组(数字 0 和字符 \0 等价)
void test()
{

    // 字符数组只能初始化 5 个字符，当输出的时候，从开始位置直到找到 0 结束
    char str1[] = {'h', 'e', 'l', 'l', 'o'};
    printf("%s\n", str1);

    // 字符数组部分初始化，剩余填 0
    char str2[100] = {'h', 'e', 'l', 'l', 'o'};
    printf("%s\n", str2);

    // 如果以字符串初始化，那么编译器默认会在字符串尾部添加 \0
    char str3[] = "hello";
    printf("%s\n", str3);
    printf("sizeof str3: %lu\n", sizeof(str3));
    printf("strlen str3: %lu\n", strlen(str3));

    // sizeof 计算数组大小，数组包含 \0 字符
    // strlen 计算字符串的长度，到 \0 结束

    // 那么如果这么写，结果是多少呢
    char str4[100] = "hello";
    printf("sizeof str4: %lu\n", sizeof(str4));
    printf("strlen str4: %lu\n", strlen(str4));

    // 请问下面输入结果是多少？sizeof 结果是多少？strlen 结果是多少
    char str5[] = "hello\0world";
    printf("%s\n", str5);
    printf("sizeof str5: %lu\n", sizeof(str5));
    printf("strlen str5: %lu\n", strlen(str5));

    // 再请问下面输入结果是多少？sizeof 结果是多少？strlen 结果是多少
    char str6[] = "hello\012world";
    printf("%s\n", str6);
    printf("sizeof str6: %lu\n", sizeof(str6));
    printf("strlen str6: %lu\n", strlen(str6));
}

int main()
{
    test();

    /*
        hello
        hello
        hello
        sizeof str3: 6
        strlen str3: 5
        sizeof str4: 100
        strlen str4: 5
        hello
        sizeof str5: 12
        strlen str5: 5
        hello
        world
        sizeof str6: 12
        strlen str6: 11
    */

    return 0;
}