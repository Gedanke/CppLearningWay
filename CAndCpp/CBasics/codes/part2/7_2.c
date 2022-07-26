#include <stdio.h>

int main()
{
    char ch;

    // 符号位溢出会导致数的正负发生改变
    ch = 0x7f + 2; // 127 + 2
    printf("%d\n", ch);
    // 0111 1111
    // +2 后 1000 0001，这是负数补码，其原码为 1111 1111，结果为 -127

    // 最高位的溢出会导致最高位丢失
    unsigned char ch2;
    ch2 = 0xff + 1; // 255 + 1
    printf("%u\n", ch2);
    // 1111 1111
    // +1 后 10000 0000，char 只有 8 位最高位的溢出，结果为 0000 0000，十进制为 0

    ch2 = 0xff + 2; // 255 + 1
    printf("%u\n", ch2);
    // 1111 1111
    // +1 后 10000 0001，char 只有 8 位最高位的溢出，结果为 0000 0001，十进制为 1

    /*
        main.c: In function ‘main’:
        main.c:15:11: warning: unsigned conversion from ‘int’ to ‘unsigned char’ changes value from ‘256’ to ‘0’ [-Woverflow]
        15 |     ch2 = 0xff + 1; // 255 + 1
            |           ^~~~
        main.c:20:11: warning: unsigned conversion from ‘int’ to ‘unsigned char’ changes value from ‘257’ to ‘1’ [-Woverflow]
        20 |     ch2 = 0xff + 2; // 255 + 1
            |           ^~~~
        -127
        0
        1
    */

    return 0;
}