#include <stdio.h>

int main()
{
    char c;
    c = getchar();

    switch (c) // 参数只能是整型变量
    {
    case '1':
        printf("Ok\n");
        break; // switch 遇到 break 就中断了
    case '2':
        printf("Not OK\n");
        break;
    default: // 如果上面的条件都不满足，那么执行 default
        printf("Are u ok?\n");
    }

    /*
        3
        Are u ok?
    */

    return 0;
}
