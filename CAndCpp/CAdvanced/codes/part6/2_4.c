#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
    char name[32];
    int age;
} Teacher;

void test()
{
    FILE *fpWrite = NULL;
    fpWrite = fopen("./mydata.txt", "wb");
    if (fpWrite == NULL)
    {
        return;
    }

    Teacher teachers[] = {
        {"Aaa", 23},
        {"Bbb", 26},
        {"Ccc", 21},
        {"Ddd", 27},
        {"Eee", 28},
        {"Fff", 22},
    };
    int len = sizeof(teachers) / sizeof(Teacher);

    for (int i = 0; i < len; i++)
    {
        fwrite(&teachers[i], sizeof(teachers[i]), 1, fpWrite);
    }

    fclose(fpWrite);
    fpWrite = NULL;

    FILE *fpRead = NULL;
    fpRead = fopen("./mydata.txt", "rb");
    if (fpRead == NULL)
    {
        return;
    }

    Teacher save[len];
    fread(&save, sizeof(Teacher), len, fpRead);
    for (int i = 0; i < len; i++)
    {
        printf("Name: %s\tAge: %d\n", save[i].name, save[i].age);
    }

    fclose(fpRead);
    fpRead = NULL;
}

int main()
{
    test();

    /*
        Name: Aaa       Age: 23
        Name: Bbb       Age: 26
        Name: Ccc       Age: 21
        Name: Ddd       Age: 27
        Name: Eee       Age: 28
        Name: Fff       Age: 22
    */

    return 0;
}