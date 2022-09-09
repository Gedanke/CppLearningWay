#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void statTest1(char *argv[])
{
    // int stat(const char *pathname, struct stat *buf);
    struct stat st;
    stat(argv[1], &st);
    printf("size: %ld, uid: %d, gid: %d\n", st.st_size, st.st_uid, st.st_gid);
}

void statTest2(char *argv[])
{
    struct stat sb;
    stat(argv[1], &sb);

    // 获取文件类型
    if ((sb.st_mode & S_IFMT) == S_IFREG)
    {
        printf("普通文件\n");
    }
    else if ((sb.st_mode & S_IFMT) == S_IFDIR)
    {
        printf("目录文件\n");
    }
    else if ((sb.st_mode & S_IFMT) == S_IFLNK)
    {
        printf("链接文件\n");
    }
    else
    {
    }

    if (S_ISREG(sb.st_mode))
    {
        printf("普通文件\n");
    }
    else if (S_ISDIR(sb.st_mode))
    {
        printf("目录文件\n");
    }
    else if (S_ISLNK(sb.st_mode))
    {
        printf("链接文件\n");
    }
    else
    {
    }

    // 判断文件权限
    if (sb.st_mode & S_IROTH)
    {
        printf("---R---\n");
    }
    if (sb.st_mode & S_IWOTH)
    {
        printf("---R---\n");
    }
    if (sb.st_mode & S_IXOTH)
    {
        printf("---R---\n");
    }
}

int main(int argc, char *argv[])
{
    // statTest1(argv);

    // size: 21, uid: 0, gid: 0

    // statTest2(argv);

    /*
        普通文件
        普通文件
        ---R---
    */

    return 0;
}