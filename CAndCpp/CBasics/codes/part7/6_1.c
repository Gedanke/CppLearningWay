#include <stdio.h>

int main()
{
    char str[] = "hello world";
    char *p = str;
    *p = 'm';
    p++;
    *p = 'i';
    printf("%s\n", str);

    p = "mike jiang";
    printf("%s\n", p);

    char *q = "test";
    printf("%s\n", q);

    char str1[] = "hello world";

    char *cstr = "hello world";
    char *cstr2 = "hello world";

    printf("&str = %p\n", str);
    printf("&str1 = %p\n", str1);
    printf("&cstr = %p\n", cstr);
    printf("&cstr2 = %p\n", cstr2);

    /*
        millo world
        mike jiang
        test
        &str = 0x7ffe389dc530
        &str1 = 0x7ffe389dc53c
        &cstr = 0x561d96429014
        &cstr2 = 0x561d96429014
    */

    return 0;
}
