#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 跳过数据
void test1()
{
    char buf[1024] = {0};
    // 跳过前面的数字
    // 匹配第一个字符是否是数字，如果是，则跳过
    // 如果不是则停止匹配
    sscanf("123456aaaa", "%*d%s", buf);
    printf("buf: %s\n", buf);
}

// 2. 读取指定宽度数据
void test2()
{
    char buf[1024] = {0};
    // 跳过前面的数字
    sscanf("123456aaaa", "%7s", buf);
    printf("buf: %s\n", buf);
}

// 3. 匹配 a-z 中任意字符
void test3()
{
    char buf[1024] = {0};
    // 跳过前面的数字
    // 先匹配第一个字符，判断字符是否是 a-z 中的字符，如果是匹配
    // 如果不是停止匹配
    sscanf("abcdefg123456", "%[a-z]", buf);
    printf("buf: %s\n", buf);
}

// 4. 匹配 aBc 中的任何一个
void test4()
{
    char buf[1024] = {0};
    // 跳过前面的数字
    // 先匹配第一个字符是否是 aBc 中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("abcdefg123456", "%[aBc]", buf);
    printf("buf: %s\n", buf);
}

// 5. 匹配非 a 的任意字符
void test5()
{
    char buf[1024] = {0};
    // 跳过前面的数字
    // 先匹配第一个字符是否是 aBc 中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("bcdefag123456", "%[^a]", buf);
    printf("buf: %s\n", buf);
}

// 6. 匹配非 a-z 中的任意字符
void test6()
{
    char buf[1024] = {0};
    // 跳过前面的数字
    // 先匹配第一个字符是否是 aBc 中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("123456ABCDbcdefag", "%[^a-z]", buf);
    printf("buf: %s\n", buf);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    /*
        buf: aaaa
        buf: 123456a
        buf: abcdefg
        buf: a
        buf: bcdef
        buf: 123456ABCD
    */

    return 0;
}