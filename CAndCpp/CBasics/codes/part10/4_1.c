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

    // 假如已经往文件写入 3 个结构体
    // fwrite(s, sizeof(Stu), 3, fp);

    Stu s[3];
    Stu tmp;
    int ret = 0;

    // 文件光标读写位置从开头往右移动 2 个结构体的位置
    fseek(fp, 2 * sizeof(Stu), SEEK_SET);

    //读第 3 个结构体
    ret = fread(&tmp, sizeof(Stu), 1, fp);
    if (ret == 1)
    {
        printf("[tmp]%s, %d\n", tmp.name, tmp.id);
    }

    // 把文件光标移动到文件开头
    // fseek(fp, 0, SEEK_SET);
    rewind(fp);

    ret = fread(s, sizeof(Stu), 3, fp);
    printf("ret = %d\n", ret);

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("s === %s, %d\n", s[i].name, s[i].id);
    }

    /*
        [tmp]stu222, 3
        ret = 3
        s === stu000, 1
        s === stu111, 2
        s === stu222, 3
    */

    return 0;
}
