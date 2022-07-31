#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char **args)
{
    if (argc < 2)
        return 0;

    struct stat st = {0};

    stat(args[1], &st);
    int size = st.st_size; // 得到结构体中的成员变量
    printf("%d\n", size);

    return 0;
}
