#include <stdio.h>

struct complex
{
    float re;
    float im;
};
struct complex topla(struct complex x1, struct complex x2);

struct complex topla(struct complex x1, struct complex x2)
{
    int ima = x1.im + x2.im;
    int real = x1.re + x2.re;
    struct complex x3;
    x3.re = real;
    x3.im = ima;
    return x3;
}

int main()
{
    struct complex x1;
    x1.re = 2;
    x1.im = 3;

    struct complex x2 = {1, 4};
    x2.re = 1;
    x2.im = 4;

    struct complex x3 = topla(x1, x2);
    printf("%d %d", x3.re, x3.im);
}
