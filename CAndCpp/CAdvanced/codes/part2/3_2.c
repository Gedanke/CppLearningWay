#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(char **p /* out */, int *len)
{
    char *tmp = (char *)malloc(100);
    if (tmp == NULL)
    {
        return;
    }
    strcpy(tmp, "adlsgjldsk");

    // 间接赋值
    *p = tmp;
    *len = strlen(tmp);
}

void test(void)
{
    // 输出，被调用函数分配内存，地址传递
    char *p = NULL;
    int len = 0;
    fun(&p, &len);
    if (p != NULL)
    {
        printf("p = %s, len = %d\n", p, len);
    }
}

int main()
{
    test();

    /*
        p = adlsgjldsk, len = 10
    */

    return 0;
}