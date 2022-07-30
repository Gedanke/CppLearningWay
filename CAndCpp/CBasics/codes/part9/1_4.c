#include <stdio.h>

struct person
{
    char name[20];
    char sex;
};

struct stu
{
    int id;
    struct person info;
};

int main()
{
    struct stu s[2] = {1, "lily", 'F', 2, "yuri", 'M'};

    int i = 0;
    for (i = 0; i < 2; i++)
    {
        printf("id = %d\tinfo.name = %s\tinfo.sex = %c\n", s[i].id, s[i].info.name, s[i].info.sex);
    }

    /*
        id = 1  info.name = lily        info.sex = F
        id = 2  info.name = yuri        info.sex = M
    */

    return 0;
}
