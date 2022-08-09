#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct Teacher
{
    char a;
    int b;
} Teacher;

void test()
{
    Teacher t;
    Teacher *p = &t;

    int offset1 = (int)&(p->b) - (int)p;
    int offset2 = offsetof(Teacher, b);

    printf("offset1: %d\n", offset1);
    printf("offset2: %d\n", offset2);
}

int main()
{
    test();

    /*
        main.c: In function ‘test’:
        main.c:16:19: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
        16 |     int offset1 = (int)&(p->b)-(int)p;
            |                   ^
        main.c:16:32: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
        16 |     int offset1 = (int)&(p->b)-(int)p;
            |                                ^
        offset1: 4
        offset2: 4
    */

    return 0;
}