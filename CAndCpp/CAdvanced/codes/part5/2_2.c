#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 一个老师有多个学生
typedef struct Teacher
{
    char *name;
    char **students;
} Teacher;

void createTeacher(Teacher **teacher, int n, int m)
{
    if (teacher == NULL)
    {
        return;
    }

    Teacher *teachers = (Teacher *)malloc(sizeof(Teacher) * n);
    if (teachers == NULL)
    {
        return;
    }

    // 给 n 个老师分配 m 个学生
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        // 分配 name
        teachers[i].name = (char *)malloc(sizeof(char) * 32);
        sprintf(teachers[i].name, "Teacher_%d", i + 1);
        // 第一次分配 students
        teachers[i].students = (char **)malloc(sizeof(char *) * 32);
        for (int j = 0; j < m; j++)
        {
            // 第二次分配 students[j]
            teachers[i].students[j] = (char *)malloc(sizeof(char *) * 32);
            sprintf(teachers[i].students[j], "Student_%d", num + 1);
            num++;
        }
    }

    *teacher = teachers;
}

void printTeacher(const Teacher *teacher, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s: \n", teacher[i].name);
        for (int j = 0; j < m; j++)
        {
            printf("%s\t", teacher[i].students[j]);
        }
        printf("\n");
    }
}

void freeTeacher(Teacher **teacher, int n, int m)
{
    if (teacher == NULL)
    {
        return;
    }

    Teacher *tmp = *teacher;

    for (int i = 0; i < n; i++)
    {
        // 释放 name
        if (tmp[i].name != NULL)
        {
            free(tmp[i].name);
            tmp[i].name = NULL;
        }
        for (int j = 0; j < m; j++)
        {
            // 释放 students[j]
            if (tmp[i].students[j] != NULL)
            {
                free(tmp[i].students[j]);
                tmp[i].students[j] = NULL;
            }
        }
        // 释放 students
        if (tmp[i].students != NULL)
        {
            free(tmp[i].students);
            tmp[i].students = NULL;
        }
    }

    // 释放 tmp
    free(tmp);
}

void test()
{
    Teacher *p = NULL;
    createTeacher(&p, 3, 3);
    printTeacher(p, 3, 3);
    freeTeacher(&p, 3, 3);
}

int main()
{
    test();

    /*
        Teacher_1:
        Student_1       Student_2       Student_3
        Teacher_2:
        Student_4       Student_5       Student_6
        Teacher_3:
        Student_7       Student_8       Student_9
    */

    return 0;
}