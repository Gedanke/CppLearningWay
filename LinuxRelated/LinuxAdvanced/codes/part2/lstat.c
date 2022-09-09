#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void lstatTest(char *argv[])
{
    // int lstat(const char *pathname, struct stat *buf);
    struct stat st;
    lstat(argv[1], &st);
    printf("size: %ld, uid: %d, gid: %d\n", st.st_size, st.st_uid, st.st_gid);
}

int main(int argc, char *argv[])
{
    lstatTest(argv);

    // size: 21, uid: 0, gid: 0

    return 0;
}