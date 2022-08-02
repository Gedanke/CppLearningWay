#include <stdio.h>

struct stus
{
    char name[20];
    int age;
    char tel[15];
    float scores[3];
    char sex;
} stu;

int main()
{
    printf("%lu\n", sizeof(stu));

    /*
        56
    */

    return 0;
}