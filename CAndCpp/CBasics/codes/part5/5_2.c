#include <stdio.h>

// C 语言没有字符串类型，通过字符数组模拟
// C 语言字符串，以字符 \0，数字 0
int main()
{
    // 不指定长度, 没有 0 结束符，有多少个元素就有多长
    char buff[] = {'a', 'b', 'c'};
    printf("buff = %s\n", buff); //乱码

    // 指定长度，后面没有赋值的元素，自动补 0
    char buf2[100] = {'a', 'b', 'c'};
    char buf[1000] = {"hello"};
    printf("buf2 = %s\n", buf2);

    // 所有元素赋值为 0
    char buf3[100] = {0};

    // char buf4[2] = {'1', '2', '3'}; // 数组越界

    char buf5[50] = {'1', 'a', 'b', '0', '7'};
    printf("buf5 = %s\n", buf5);

    char buf6[50] = {'1', 'a', 'b', 0, '7'};
    printf("buf6 = %s\n", buf6);

    char buf7[50] = {'1', 'a', 'b', '\0', '7'};
    printf("buf7 = %s\n", buf7);

    // 使用字符串初始化，编译器自动在后面补 0，常用
    char buf8[] = "agjdslgjlsdjg";

    // \0 后面最好不要连着数字，有可能几个数字连起来刚好是一个转义字符
    // \ddd 八进制字义字符，\xdd 十六进制转移字符
    // \012 相当于 \n
    char str[] = "\012abc";
    printf("str == %s\n", str);

    /*
        buff = abc
        buf2 = abc
        buf5 = 1ab07
        buf6 = 1ab
        buf7 = 1ab
        str ==
        abc
    */

    return 0;
}
