#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[100] = "adc*fvcv.ebcy*hghbdfg$casdert";
    char *s = strtok(a, ".*$"); // 将 "*" 分割的子串取出
    while (s != NULL)
    {
        printf("%s\n", s);
        s = strtok(NULL, "*");
    }

    /*
        adc
        fvcv.ebcy
        hghbdfg$casdert
    */

    return 0;
}