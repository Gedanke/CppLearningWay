#include <stdio.h>

enum weekday
{
    sun = 2,
    mon,
    tue,
    wed,
    thu,
    fri,
    sat
};

enum bool
{
    flase,
    true
};

int main()
{
    enum weekday a, b, c;
    a = sun;
    b = mon;
    c = tue;
    printf("%d, %d, %d\n", a, b, c);

    enum bool flag;
    flag = true;

    if (flag == 1)
    {
        printf("flag 为真\n");
    }

    /*
        2, 3, 4
        flag 为真
    */

    return 0;
}