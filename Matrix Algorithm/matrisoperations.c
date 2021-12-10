#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrisoperations.h"

int matris1[5][5] = {{21, 19, 17, 25, 28}, {71, 76, 73, 68, 59}, {153, 154, 164, 157, 155}, {200, 201, 190, 185, 180}, {205, 210, 215, 230, 232}};
int matris2[3][3] = {{-1, -1, -1}, {-1, 8, -1}, {-1, -1, -1}};
int size1 = 25;
int size2 = 9;

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

    int **cozumMatris = matrisOlustur(cozumMatrisSize);
    if (islemTipi == 0)
    {
        notExpandedMatrisOperation(matris1, matris2, cozumMatris, matris1Size, matris2Size, cozumMatrisSize);
    }

    // matrisYazdirma(cozumMatris, cozumMatrisSize);
    //matrisFree(cozumMatris, cozumMatrisSize);

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
}
void matrisFree(int **matris, int size)
{
    int i;
    for (i = 0; i < size; i++) //SIL
    {
        free(*(matris + i));
    }
    free(matris);
}
int **matrisOlustur(int size)
{
    int **matris3 = (int **)calloc(size, sizeof(int *)); //Her satir ayri ayri free edilmeli
    int i;
    for (i = 0; i < size; i++)
    {
        *(matris3 + i) = (int *)calloc(size, sizeof(int));
    }
    return matris3;
}
void notExpandedMatrisOperation(int **matris1, int **matris2, int **cozumMatris, int matris1Size, int matris2Size, int cozumMatrisSize)
{
}
