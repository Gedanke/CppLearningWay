#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("a = %p\n", a);
    printf("&a[0] = %p\n", &a[0]);

    // a = 10; // err，数组名只是常量，表达式必须是可修改的左值

    /*
        a = 0x7ffd12f9b8b0
        &a[0] = 0x7ffd12f9b8b0
    */

    return 0;
}
