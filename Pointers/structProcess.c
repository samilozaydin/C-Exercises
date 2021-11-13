#include <stdio.h>
#include "structHeader.h"

int main()
{
    struct complex x1;
    x1.re = 2;
    x1.im = 3;

    struct complex x2 = {1, 4};
    x2.re = 1;
    x2.im = 4;
    struct complex x3 = {5, 9};
    struct complex arr[3] = {x1, x2, x3};

    struct complex x4 = topla(&x1, &x2);

    yazdirKarmasik(&x1);
    yazdirKarmasikDizi(arr, 3);
}
