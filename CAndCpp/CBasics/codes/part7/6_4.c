#include <stdio.h>

// argc: 传参数的个数(包含可执行程序)
// argv：指针数组，指向输入的参数
int main(int argc, char *argv[])
{

    // 指针数组，它是数组，每个元素都是指针
    char *a[] = {"aaaaaaa", "bbbbbbbbbb", "ccccccc"};
    int i = 0;

    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    // gcc -o main main.c && ./main

    /*
        argc = 1
        ./main
    */

    return 0;
}
