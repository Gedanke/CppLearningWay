#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    // 打开目录
    // DIR *opendir(const char *name);
    DIR *pDir = opendir(argv[1]);
    if (pDir == NULL)
    {
        perror("opendir error");
        return -1;
    }

    // 循环读取目录项
    // struct dirent *readdir(DIR *dirp);
    struct dirent *pDent = NULL;
    while ((pDent = readdir(pDir)) != NULL)
    {
        // 过滤掉 . 和 .. 文件
        if (strcmp(pDent->d_name, ".") == 0 || strcmp(pDent->d_name, "..") == 0)
        {
            continue;
        }
        printf("%s ----> ", pDent->d_name);

        // 判断文件类型
        switch (pDent->d_type)
        {
        case DT_REG:
        {
            printf("普通文件\n");
            break;
        }
        case DT_DIR:
        {
            printf("目录文件\n");
            break;
        }
        case DT_LNK:
        {
            printf("链接文件\n");
            break;
        }
        default:
        {
            printf("未知文件\n");
        }
        }
    }

    // 关闭目录
    closedir(pDir);

    /*
        makefile ----> 普通文件
        .vscode ----> 目录文件
        test ----> 目录文件
        testc ----> 目录文件
    */

    return 0;
}