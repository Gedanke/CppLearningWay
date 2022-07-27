#include <stdio.h>
#include "a.h"

int main()
{

    /*
        ...
        a.h:1:15: error: #include nested too deeply
        1 | #include "b.h"
        |
    */

    return 0;
}