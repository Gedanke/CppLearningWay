#include <stdio.h>

int main()
{
    unsigned int a;
    scanf("%u", &a);

    if (a < 10)
    {
        printf("个位\n");
    }
    else if (a < 100)
    {
        printf("十位\n");
    }
    else if (a < 1000)
    {
        printf("百位\n");
    }
    else
    {
        printf("很大\n");
    }

    /*
        1024
        很大
    */

    return 0;
}
