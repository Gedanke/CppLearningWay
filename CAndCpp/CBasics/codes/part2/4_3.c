#include <stdio.h>

int main()
{
    printf("abc");
    printf("\refg\n"); // \r 切换到句首，\n 为换行键

    printf("abc");
    printf("\befg\n"); // \b 为退格键，\n 为换行键

    printf("%d\n", '\123'); // \123 为 8 进制转义字符，0123 对应 10 进制数为 83
    printf("%d\n", '\x23'); // \x23 为 16 进制转义字符，0x23 对应 10 进制数为 35

    /*
        efg
        abefg
        83
        35
    */

    return 0;
}