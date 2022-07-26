#include <stdio.h>

int main()
{
    char str[100];

    printf("input string: \n");
    scanf("%s", str); // scanf("%s", str) // 默认以空格分隔
    printf("output:%s\n", str);

    /*
        input string:
        string string
        output:string
    */

    return 0;
}
