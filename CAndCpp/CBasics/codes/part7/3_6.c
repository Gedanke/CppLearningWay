#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p2 = &a[2]; // 第 2 个元素地址
    int *p1 = &a[1]; // 第 1 个元素地址
    printf("p1 = %p, p2 = %p\n", p1, p2);

    int n1 = p2 - p1;           // n1 = 1
    int n2 = (int)p2 - (int)p1; // n2 = 4
    printf("n1 = %d, n2 = %d\n", n1, n2);

    /*
        main.c: In function ‘main’:
        main.c:11:14: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
        11 |     int n2 = (int)p2 - (int)p1; // n2 = 4
            |              ^
        main.c:11:24: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
        11 |     int n2 = (int)p2 - (int)p1; // n2 = 4
            |                        ^
        p1 = 0x7fffcfb4cce4, p2 = 0x7fffcfb4cce8
        n1 = 1, n2 = 4
    */

    return 0;
}
