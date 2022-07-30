#include <stdio.h>

// 统计学生成绩
struct stu
{
    int num;
    char name[20];
    char sex;
    float score;
};

int main()
{
    // 定义一个含有 5 个元素的结构体数组并将其初始化
    struct stu boy[5] = {
        {101, "Li ping", 'M', 45},
        {102, "Zhang ping", 'M', 62.5},
        {103, "He fang", 'F', 92.5},
        {104, "Cheng ling", 'F', 87},
        {105, "Wang ming", 'M', 58}};

    int i = 0;
    int c = 0;
    float ave, s = 0;
    for (i = 0; i < 5; i++)
    {
        s += boy[i].score; // 计算总分
        if (boy[i].score < 60)
        {
            c += 1; // 统计不及格人的分数
        }
    }

    printf("s = %f\n", s);                        // 打印总分数
    ave = s / 5;                                  // 计算平均分数
    printf("average = %f\ncount = %d\n", ave, c); // 打印平均分与不及格人数

    printf("message:\n");
    for (i = 0; i < 5; i++)
    {
        printf("name = %s, score = %f\n", boy[i].name, boy[i].score);
        // printf(" name=%s,  score=%f\n", (boy+i)->name, (boy+i)->score);
    }

    /*
        s = 345.000000
        average = 69.000000
        count = 2
        message:
        name = Li ping, score = 45.000000
        name = Zhang ping, score = 62.500000
        name = He fang, score = 92.500000
        name = Cheng ling, score = 87.000000
        name = Wang ming, score = 58.000000
    */

    return 0;
}
