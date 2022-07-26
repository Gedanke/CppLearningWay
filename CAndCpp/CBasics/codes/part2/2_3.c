#include <stdio.h>

int main()
{
    short a = 10;
    int b = 10;
    long c = 10l;       // 或者 10L
    long long d = 10ll; // 或者 10LL

    printf("sizeof(a) = %lu\n", sizeof(a));
    printf("sizeof(b) = %lu\n", sizeof(b));
    printf("sizeof(c) = %lu\n", sizeof(c));
    printf("sizeof(c) = %lu\n", sizeof(d));

    printf("short a = %hd\n", a);
    printf("int b = %d\n", b);
    printf("long c = %ld\n", c);
    printf("long long d = %lld\n", d);

    unsigned short a2 = 20u;
    unsigned int b2 = 20u;
    unsigned long c2 = 20ul;
    unsigned long long d2 = 20ull;

    printf("unsigned short a = %hu\n", a2);
    printf("unsigned int b = %u\n", b2);
    printf("unsigned long c = %lu\n", c2);
    printf("unsigned long long d = %llu\n", d2);

    /*
        sizeof(a) = 2
        sizeof(b) = 4
        sizeof(c) = 8
        sizeof(c) = 8
        short a = 10
        int b = 10
        long c = 10
        long long d = 10
        unsigned short a = 20
        unsigned int b = 20
        unsigned long c = 20
        unsigned long long d = 20
    */

    return 0;
}