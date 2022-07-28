#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // const 修饰一个变量为只读
    const int a = 10;
    // a = 100; // err

    // 指针变量，指针指向的内存，2 个不同概念
    char buf[] = "aklgjdlsgjlkds";

    // 从左往右看，跳过类型，看修饰哪个字符
    // 如果是 *， 说明指针指向的内存不能改变
    // 如果是指针变量，说明指针的指向不能改变，指针的值不能修改
    const char *p = buf;
    // 等价于上面 char const *p1 = buf;
    // p[1] = '2'; // err
    p = "agdlsjaglkdsajgl"; // ok

    char *const p2 = buf;
    p2[1] = '3';
    // p2 = "salkjgldsjaglk"; // err

    // p3 为只读，指向不能变，指向的内存也不能变
    const char *const p3 = buf;

    return 0;
}
