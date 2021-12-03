#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SATIR 4
#define SUTUN 3

int main()
{

    float *dizi;
    float **dizi2;

    dizi = diziOlustur(SATIR);
    dizi2 = ikiBoyutluDiziOlustur(SATIR, SUTUN);

    diziDoldur(dizi, SATIR);
    diziYazdir(dizi, SATIR);
    puts("");

    ikiBoyutluDiziDoldur(dizi2, SATIR, SUTUN);
    ikiBoyutluDiziYazdir(dizi2, SATIR, SUTUN);

    return 0;
}