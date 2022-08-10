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
        {"Obama", 33},
        {"John", 28},
        {"Edward", 45},
        {"Smith", 35}};

    int len = sizeof(teachers) / sizeof(teachers[0]);

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

    Teacher save;
    long idx = ftell(fpRead);
    printf("File poninter: %ld\n", idx);

    // 读取第三个数组
    fseek(fpRead, sizeof(Teacher) * 2, SEEK_SET);
    idx = ftell(fpRead);
    fread(&save, sizeof(Teacher), 1, fpRead);
    printf("File poninter: %ld\n", idx);
    printf("Name: %s\tAge: %d\n", save.name, save.age);

    // 读取第二个数组
    fseek(fpRead, -sizeof(Teacher) * 2, SEEK_CUR);
    idx = ftell(fpRead);
    fread(&save, sizeof(Teacher), 1, fpRead);
    printf("File poninter: %ld\n", idx);
    printf("Name: %s\tAge: %d\n", save.name, save.age);

    // 读取第四个数组
    fseek(fpRead, -sizeof(Teacher), SEEK_END);
    idx = ftell(fpRead);
    fread(&save, sizeof(Teacher), 1, fpRead);
    printf("File poninter: %ld\n", idx);
    printf("Name: %s\tAge: %d\n", save.name, save.age);

    // 读取第一个数组
    rewind(fpRead);
    idx = ftell(fpRead);
    fread(&save, sizeof(Teacher), 1, fpRead);
    printf("File poninter: %ld\n", idx);
    printf("Name: %s\tAge: %d\n", save.name, save.age);

    fclose(fpRead);
    fpRead = NULL;
}

int main()
{
    test();

    /*
        File poninter: 0
        File poninter: 72
        Name: Edward    Age: 45
        File poninter: 36
        Name: John      Age: 28
        File poninter: 108
        Name: Smith     Age: 35
        File poninter: 0
        Name: Obama     Age: 33
    */

    return 0;
}