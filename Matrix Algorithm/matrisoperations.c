#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrisoperations.h"

int matrisDeneme1[5][5] = {{21, 19, 17, 25, 28}, {71, 76, 73, 68, 59}, {153, 164, 164, 157, 155}, {200, 201, 190, 185, 180}, {205, 210, 215, 230, 232}};
int matrisDeneme2[3][3] = {{-1, -1, -1}, {-1, 8, -1}, {-1, -1, -1}};
int size1 = 25;
int size2 = 9;

int **operasyon1(int **matris1, int **matris2, int islemTipi, int matris1Size, int matris2Size)
{
    //DENEME ALANI ICIN
    matris1Size = size1;
    matris2Size = size2;

    int *p1 = matrisDeneme1[0];
    int *p2 = matrisDeneme1[1];
    int *p3 = matrisDeneme1[2];
    int *p4 = matrisDeneme1[3];
    int *p5 = matrisDeneme1[4];

    int **pR1 = (int **)malloc(5 * sizeof(int *));
    *(pR1) = p1;
    *(pR1 + 1) = p2;
    *(pR1 + 2) = p3;
    *(pR1 + 3) = p4;
    *(pR1 + 4) = p5;

    int *p12 = matrisDeneme2[0];
    int *p22 = matrisDeneme2[1];
    int *p32 = matrisDeneme2[2];

    int **pR2 = (int **)malloc(5 * sizeof(int *));
    *(pR2) = p12;
    *(pR2 + 1) = p22;
    *(pR2 + 2) = p32;

    matris2 = pR2;
    matris1 = pR1;
    //DENEME ALANI ICIN
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

    int **cozumMatris = matrisOlustur(cozumMatrisSize);

    if (islemTipi == 0)
    {
        notExpandedMatrisOperation(matris1, matris2, cozumMatris, matris1Size, matris2Size, cozumMatrisSize);
    }

    //matrisYazdirma(cozumMatris, cozumMatrisSize);
    matrisFree(cozumMatris, cozumMatrisSize);

    //DENEME ALANI FREE
    int z;
    for (z = 0; z < 5; z++)
    {
        free(matris1 + z);
    }
    free(matris1);
    for (z = 0; z < 3; z++)
    {
        free(matris2 + z);
    }
    free(matris2);
    //DENEME ALANI FREE
    return NULL;
}
void matrisYazdirma(int **matris, int size)
{
    int i, j;
    for (i = 0; i < size; i++) //SIL
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
    int i;
    free(*matris);
    free(matris);
}
int **matrisOlustur(int size)
{
    int **matris3 = (int **)malloc(size * sizeof(int *)); //Sadece matris[0] free edilse yeterli
    *(matris3) = (int *)calloc(size * size, sizeof(int));
    int i;

    for (i = 1; i < size; i++)
    {
        *(matris3 + i) = *(matris3) + i * size;
    }

    return matris3;
}
void notExpandedMatrisOperation(int **matris1, int **matris2, int **cozumMatris, int matris1Size, int matris2Size, int cozumMatrisSize) //matris 1 ve matris 2 tam kare halinde, cozum matris ise tam kare halinde olmadan yollanir. 3x3 ise cozumMatrisSize 3 olur.
{
    int matris1Rw = sqrt(matris1Size);
    int matris2Rw = sqrt(matris2Size);
    int cozumMatrisSizeOf = cozumMatrisSize * cozumMatrisSize;
    int sum = 0;
    int counter = 0;
    int i, j, k;
    int position = 0, positionCol = 0;

    int *ptrMatris1 = *matris1;
    int *ptrMatris2 = *matris2;
    int *ptrCozumMatris = *cozumMatris;

    int *temporaryMatris = (int *)malloc(sizeof(int) * matris2Size); //gecici olarak olusturulan her bir cozumMatris hucresindeki elemanı olusturmaya yardimci olacak matris.
    for (i = 0; i < cozumMatrisSizeOf; i++)
    {
        temporaryMatrisOlustur(temporaryMatris, ptrMatris1, matris1Rw, matris2Rw, i);
        cozumMatrisDoldur(temporaryMatris, ptrMatris2, ptrCozumMatris, i, cozumMatrisSizeOf);
    }

    matrisYazdirma(cozumMatris, cozumMatrisSize);
    free(temporaryMatris);
}
void temporaryMatrisOlustur(int *matris, int *ptrMatris1, int matris1Rw, int matris2Rw, int position)
{
    int j;
    int size = matris2Rw * matris2Rw;
    for (j = 0; j < size; j++)
    {
        *(matris + j) = *(ptrMatris1 + position + j + (matris1Rw - matris2Rw) * (j / matris2Rw) + (position / matris2Rw) * (matris1Rw - matris2Rw));
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