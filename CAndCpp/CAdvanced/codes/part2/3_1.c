#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(char *p /* in */)
{
    // 给 p 指向的内存区域拷贝内容
    strcpy(p, "abcddsgsd");
}

void test(void)
{
    // 输入，主调函数分配内存
    char buf[100] = {0};
    fun(buf);
    printf("buf  = %s\n", buf);
}

int main()
{
    test();

    /*
        buf  = abcddsgsd
    */

    return 0;
}