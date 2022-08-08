#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1()
{
    char *ip = "127.0.0.1";
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;

    sscanf(ip, "%d.%d.%d.%d", &num1, &num2, &num3, &num4);
    printf("%d %d %d %d\n", num1, num2, num3, num4);
}

void test2()
{
    char *str = "abcdef#zhangtao@123456";
    char buf[1024] = {0};

    sscanf(str, "%*[^#]#%[^@]", buf);
    printf("%s\n", buf);
}

void test3()
{
    char *str1 = "helloworld@itcast.cn";
    char *str2 = "123abcd$myname@000qwe";
    char buf1[1024] = {0};
    char buf2[1024] = {0};
    char buf3[1024] = {0};
    sscanf(str1, "%[a-z]%*[@]%s", buf1, buf2);
    sscanf(str2, "%*[^$]$%[^@]", buf3);

    printf("%s\n", buf1);
    printf("%s\n", buf2);
    printf("%s\n", buf3);
}

int main()
{
    test1();
    test2();
    test3();

    /*
        127 0 0 1
        zhangtao
        helloworld
        itcast.cn
        myname
    */

    return 0;
}