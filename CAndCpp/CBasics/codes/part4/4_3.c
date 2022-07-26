#include <stdio.h>

int main()
{
    goto End; // 无条件跳转到 End 的标识
    printf("aaaaaaaaa\n");

End:
{
    printf("bbbbbbbb\n");
    printf("cccccccc\n");
}
    printf("dddddddd\n");

    /*
        bbbbbbbb
        cccccccc
        dddddddd
    */

    return 0;
}