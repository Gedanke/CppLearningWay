#include <stdio.h>

int main()
{
    int i = 0;
    while (1)
    {
        i++;
        printf("i = %d\n", i);

        if (i == 3)
        {
            break; // 跳出 while 循环
        }
    }

    int flag = 0;
    int m = 0;
    int n = 0;

    for (m = 0; m < 10; m++)
    {
        for (n = 0; n < 10; n++)
        {
            if (n == 5)
            {
                flag = 1;
                break; // 跳出 for (n = 0; n < 10; n++)
            }
        }

        if (flag == 1)
        {
            break; // 跳出 for (m = 0; m < 10; m++)
        }
    }

    /*
        i = 1
        i = 2
        i = 3
    */

    return 0;
}
