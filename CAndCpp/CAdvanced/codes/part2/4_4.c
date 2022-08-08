#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    // 1. 格式化字符串
    char buf[1024] = {0};
    sprintf(buf, "你好，%s，欢迎加入我们!", "John");
    printf("buf: %s\n", buf);

    memset(buf, 0, 1024);
    sprintf(buf, "我今年 %d 岁了!", 20);
    printf("buf: %s\n", buf);

    // 2. 拼接字符串
    memset(buf, 0, 1024);
    char str1[] = "hello";
    char str2[] = "world";
    int len = sprintf(buf, "%s %s", str1, str2);
    printf("buf: %s len: %d\n", buf, len);

    int num = 100;

    // 3. 数字转字符串
    memset(buf, 0, 1024);
    sprintf(buf, "%d", num);
    printf("buf: %s\n", buf);

    // 设置宽度，右对齐
    memset(buf, 0, 1024);
    sprintf(buf, "%8d", num);
    printf("buf: %s\n", buf);

    // 设置宽度，左对齐
    memset(buf, 0, 1024);
    sprintf(buf, "%-8d", num);
    printf("buf: %s\n", buf);

    // 转成 16 进制字符串，小写
    memset(buf, 0, 1024);
    sprintf(buf, "0x%x", num);
    printf("buf: %s\n", buf);

    // 转成 8 进制字符串
    memset(buf, 0, 1024);
    sprintf(buf, "0%o", num);
    printf("buf: %s\n", buf);
}

int main()
{
    test();

    /*
        buf: 你好，John，欢迎加入我们!
        buf: 我今年 20 岁了!
        buf: hello world len: 11
        buf: 100
        buf:      100
        buf: 100
        buf: 0x64
        buf: 0144
    */

    return 0;
}