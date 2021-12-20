/*
* @file matrisoperations.c
* @description This program is a matrix algorithm.
* @assignment Project 1
* @date 11.12.2021
* @author Samil Bilal OZAYDIN samilbilal.ozaydin@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrisoperations.h"
#include <stdlib.h>
#include <time.h>

int CozumMatrisSize;

int **operasyon1(int **matris1, int **matris2, int islemTipi, int matris1Size, int matris2Size)
{

    int cozumMatrisSize;
    int matris1Rw = sqrt(matris1Size);
    int matris2Rw = sqrt(matris2Size);

    if (islemTipi == 0)
    { //islem tipinin girdisinin 0 ve 1 disinda olmadigini kontrol et
        cozumMatrisSize = ((matris1Rw - matris2Rw) / (1)) + 1;
    }
    else
    {
        int D = (matris2Rw - 1) / 2;
        cozumMatrisSize = ((matris1Rw - matris2Rw + 2 * D) / (1)) + 1;
    }

    CozumMatrisSize = cozumMatrisSize;
    int **cozumMatris = matrisOlustur(cozumMatrisSize);

    if (islemTipi == 0)
    {
        notExpandedMatrisOperation(matris1, matris2, cozumMatris, matris1Size, matris2Size, cozumMatrisSize);
    }
    else if (islemTipi == 1)
    {
        ExpandedMatrisOperation(matris1, matris2, cozumMatris, matris1Size, matris2Size, cozumMatrisSize);
    }
    return cozumMatris;
}
void matrisYazdirma(int **matris, int size)
{ //Size boyutu 7x7'nin 7 si olarak gelir. 49 degil.
    int i, j;
    printf("-----------------------------------------\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d\t", *(*(matris + i) + j));
        }
        printf("\n");
    }
    printf("-----------------------------------------");
}
void matrisFree(int **matris, int size)
{
    free(*matris);
    free(matris);
}
int **matrisOlustur(int size)
{
    //Gelen size'lar 7x7'nin sadece 7'sidir. 49 degil.
    int **matris3 = (int **)malloc(size * sizeof(int *)); //Sadece matris[0] free edilse yeterli
    *(matris3) = (int *)calloc(size * size, sizeof(int));
    int i;

    for (i = 1; i < size; i++)
    {
        *(matris3 + i) = *(matris3) + i * size;
    }

    return matris3;
}
void matrisDoldur(int **matris, int sizeRw)
{
    int i, j;
    for (i = 0; i < sizeRw; i++)
    {
        for (j = 0; j < sizeRw; j++)
        {
            matris[i][j] = (rand() % 10) + 1;
        }
    }
}
void notExpandedMatrisOperation(int **matris1, int **matris2, int **cozumMatris, int matris1Size, int matris2Size, int cozumMatrisSize) //matris 1 ve matris 2 tam kare halinde, cozum matris ise tam kare halinde olmadan yollanir. 3x3 ise cozumMatrisSize 3 olur.
{
    int matris1Rw = sqrt(matris1Size);
    int matris2Rw = sqrt(matris2Size);
    int cozumMatrisSizeOf = cozumMatrisSize * cozumMatrisSize;
    int sum = 0;
    int i;

    int *ptrMatris1 = *matris1;
    int *ptrMatris2 = *matris2;
    int *ptrCozumMatris = *cozumMatris;

    int *temporaryMatris = (int *)malloc(sizeof(int) * matris2Size); //gecici olarak olusturulan her bir cozumMatris hucresindeki elemanı olusturmaya yardimci olacak matris.Matris1'in cesitli konumlardaki elemanlarini edinir.
    for (i = 0; i < cozumMatrisSizeOf; i++)
    {
        temporaryMatrisOlustur(temporaryMatris, ptrMatris1, matris1Rw, matris2Rw, i, cozumMatrisSize);
        cozumMatrisDoldur(temporaryMatris, ptrMatris2, ptrCozumMatris, i, matris2Size);
    }
    free(temporaryMatris);
}
void temporaryMatrisOlustur(int *matris, int *ptrMatris1, int matris1Rw, int matris2Rw, int position, int cozumMatrisRw)
{
    int j;
    int size = matris2Rw * matris2Rw;
    for (j = 0; j < size; j++)
    {
        *(matris + j) = *(ptrMatris1 + position + j + (matris1Rw - matris2Rw) * (j / matris2Rw) + (position / (matris1Rw - matris2Rw + 1)) * (matris2Rw - 1));
    }
}
void temporaryMatrisYazdir(int *point, int size)
{
    int i;
    for (i = 0; i < size * size; i++)
    {
        printf("%d ", *(point + i));
        if ((i + 1) % size == 0)
        {
            printf("\n");
        }
    }
    printf("Simdiki bitti\n");
}
void cozumMatrisDoldur(int *tempMatris, int *matris, int *cozumMatris, int index, int size)
{
    int sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += *(tempMatris + i) * *(matris + i);
    }
    *(cozumMatris + index) = sum;
}
void ExpandedMatrisOperation(int **matris1, int **matris2, int **cozumMatris, int matris1Size, int matris2Size, int cozumMatrisSize) //matris 1 ve matris 2 tam kare halinde, cozum matris ise tam kare halinde olmadan yollanir. 3x3 ise cozumMatrisSize 3 olur.
{
    int matris1Rw = sqrt(matris1Size);
    int matris2Rw = sqrt(matris2Size);
    int cozumMatrisSizeOf = cozumMatrisSize * cozumMatrisSize;
    int sum = 0;
    int i;

    int *ptrMatris2 = *matris2;
    int *ptrCozumMatris = *cozumMatris;

    int expandedMatrisSizeOf = matris1Rw + 2;
    int expandedMatrisSize = expandedMatrisSizeOf * expandedMatrisSizeOf;
    int loop = (expandedMatrisSizeOf - matris2Rw + 1) * (1 + expandedMatrisSizeOf - matris2Rw);
    int sqrtLoop = sqrt(loop);

    int **expandedMatris = matrisOlustur(expandedMatrisSizeOf);
    expandedMatrisDoldur(expandedMatris, matris1, expandedMatrisSize, matris1Size);
    printf("\nGenisletilmis matrisin icerigi: \n");
    matrisYazdirma(expandedMatris, expandedMatrisSizeOf);
    printf("-----------------------------------------\n");

    int *ptrExpandedMatris = *expandedMatris;
    int *temporaryMatris = (int *)malloc(sizeof(int) * matris2Size); //gecici olarak olusturulan her bir cozumMatris hucresindeki elemanı olusturmaya yardimci olacak matris.
    for (i = 0; i < loop; i++)
    {
        temporaryMatrisOlustur(temporaryMatris, ptrExpandedMatris, expandedMatrisSizeOf, matris2Rw, i, cozumMatrisSize);
        cozumMatrisDoldur(temporaryMatris, ptrMatris2, ptrCozumMatris, (i + (i / sqrtLoop) * (cozumMatrisSize - sqrtLoop)), matris2Size);
    }
    matrisFree(expandedMatris, expandedMatrisSizeOf);
    free(temporaryMatris);
}
void expandedMatrisDoldur(int **expandedMatris, int **matris1, int expandedMatrisSize, int matris1Size)
{
    int matris1Rw = sqrt(matris1Size);
    int expandedMatrisSizeRw = sqrt(expandedMatrisSize);
    int beginFrom = (expandedMatrisSizeRw - matris1Rw) / 2;
    int i, j;
    for (i = beginFrom; i < matris1Rw + beginFrom; i++)
    {
        for (j = beginFrom; j < matris1Rw + beginFrom; j++)
        {
            *(*(expandedMatris + i) + j) = *(*(matris1 + i - beginFrom) + j - beginFrom);
        }
    }
}