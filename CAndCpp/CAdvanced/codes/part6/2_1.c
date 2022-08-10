#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    FILE *fp = NULL;

    // \\ 这样的路径形式，只能在 windows 使用
    // / 这样的路径形式，windows 和 linux 平台下都可用，建议使用这种
    // 路径可以是相对路径，也可是绝对路径
    fp = fopen("./test", "w");
    // fp = fopen("..\\test", "w");

    if (fp == NULL) // 返回空，说明打开失败
    {
        // perror() 是标准出错打印函数，能打印调用库函数出错原因
        perror("open");
        return;
    }
    else
    {
        printf("successful!\n");
    }
}

int main()
{
    test();

    /*
        successful!
    */

    return 0;
}