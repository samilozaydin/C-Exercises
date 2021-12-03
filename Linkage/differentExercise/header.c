#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *diziOlustur(int n)
{
    float *dizi = (float *)malloc(n * sizeof(float));
    return dizi;
}

void diziDoldur(float *dizi, int n)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        dizi[i] = (rand() % 10) + 1;
    }
}
void diziYazdir(float *dizi, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%.2f  ", dizi[i]);
    }
}
int **ikiBoyutluDiziOlustur(int satir, int sutun)
{

    int **dizi = malloc(satir / sizeof(int *));
    int i;
    for (i = 0; i < satir; i++)
    {
        dizi[i] = malloc(sutun * sizeof(int));
    }
    return dizi;
}
void ikiBoyutluDiziDoldur(int **dizi, int satir, int sutun)
{
    int i, j;
    srand(time(NULL));

    for (i = 0; i < satir; i++)
    {
        for (j = 0; j < sutun; j++)
        {
            dizi[i][j] = (rand() % 10) + 1;
        }
    }
}
void ikiBoyutluDiziDoldur(int **dizi, int satir, int sutun)
{
    int i, j;
    srand(time(NULL));

    for (i = 0; i < satir; i++)
    {
        for (j = 0; j < sutun; j++)
        {
            printf("%.2d  ", dizi[i][j]);
        }
        puts("");
    }
}