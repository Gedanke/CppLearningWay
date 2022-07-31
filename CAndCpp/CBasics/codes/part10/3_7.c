#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "w");

    typedef struct Stu
    {
        char name[50];
        int id;
    } Stu;

    Stu s[3];
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        sprintf(s[i].name, "stu%d%d%d", i, i, i);
        s[i].id = i + 1;
    }

    int ret = fwrite(s, sizeof(Stu), 3, fp);
    printf("ret = %d\n", ret);

    /*
        ret = 3
    */

    return 0;
}
