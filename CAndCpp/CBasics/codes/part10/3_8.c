#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "r");

    typedef struct Stu
    {
        char name[50];
        int id;
    } Stu;

    Stu s[3];
    int ret = fread(s, sizeof(Stu), 3, fp);
    printf("ret = %d\n", ret);

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("s = %s, %d\n", s[i].name, s[i].id);
    }

    /*
        ret = 3
        s = stu000, 1
        s = stu111, 2
        s = stu222, 3
    */

    return 0;
}
