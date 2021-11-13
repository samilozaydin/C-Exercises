#include <stdio.h>
#include "structHeader.h"

struct complex
{
    float re;
    float im;
};

struct complex topla(struct complex *x1, struct complex *x2)
{
    struct complex x3;
    x3.im = x1->im + x2->im;
    x3.re = x1->re + x2->re;

    return x3;
}
struct complex carpim(struct complex *x1, struct complex *x2)
{
    struct complex x3;
    x3.im = (x1->re * x2->im) - (x1->im * x2->re);
    x3.re = (x1->re * x2->re) - (x1->im * x2->im);

    return x3;
}
void yazdirKarmasik(struct complex *per)
{

    if (per->re < 0)
    {
        printf("\nreel = %.0f imajiner = %.0f sayi = %.0f + (%.0fi)\n", per->re, per->im, per->re, per->im);
    }
    else
    {
        printf("\nreel = %.0f imajiner = %.0f sayi = %.0f + %.0fi\n", per->re, per->im, per->re, per->im);
    }
}
void yazdirKarmasikDizi(struct complex *per, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (per->re < 0)
        {
            printf("\n%d.sayi = reel = %.0f imajiner = %.0f sayi = %.0f + (%.0fi)\n", i, per->re, per->im, per->re, per->im);
        }
        else
        {
            printf("\n%d.sayi = reel = %.0f imajiner = %.0f sayi = %.0f + %.0fi\n", i, per->re, per->im, per->re, per->im);
        }
    }
}