#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrisoperations.h"

// matrisDeneme1[5][5] = {{21, 19, 17, 25, 28}, {71, 76, 73, 68, 59}, {153, 164, 164, 157, 155}, {200, 201, 190, 185, 180}, {205, 210, 215, 230, 232}};
int matrisDeneme1[5][5] = {{60, 113, 56, 139, 85}, {73, 121, 54, 84, 128}, {131, 99, 70, 129, 127}, {80, 57, 115, 69, 134}, {104, 126, 123, 95, 130}};
//int matrisDeneme2[3][3] = {{-1, -1, -1}, {-1, 8, -1}, {-1, -1, -1}};
int matrisDeneme2[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};

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
    else if (islemTipi == 1)
    {
        ExpandedMatrisOperation(matris1, matris2, cozumMatris, matris1Size, matris2Size, cozumMatrisSize);
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
{ //Size boyutu 7x7'nin 7 si olarak gelir. 49 degil.
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

    int *temporaryMatris = (int *)malloc(sizeof(int) * matris2Size); //gecici olarak olusturulan her bir cozumMatris hucresindeki elemanı olusturmaya yardimci olacak matris.
    for (i = 0; i < cozumMatrisSizeOf; i++)
    {
        temporaryMatrisOlustur(temporaryMatris, ptrMatris1, matris1Rw, matris2Rw, i, cozumMatrisSize);
        cozumMatrisDoldur(temporaryMatris, ptrMatris2, ptrCozumMatris, i, matris2Size);
    }

    matrisYazdirma(cozumMatris, cozumMatrisSize);
    free(temporaryMatris);
}
void temporaryMatrisOlustur(int *matris, int *ptrMatris1, int matris1Rw, int matris2Rw, int position, int cozumMatrisRw)
{
    int j;
    int size = matris2Rw * matris2Rw;
    for (j = 0; j < size; j++)
    {
        *(matris + j) = *(ptrMatris1 + position + j + (matris1Rw - matris2Rw) * (j / matris2Rw) + (position / cozumMatrisRw) * (matris2Rw - 1));
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
        printf("%d * %d = %d \n", *(tempMatris + i), *(matris + i), *(tempMatris + i) * *(matris + i));
        sum += *(tempMatris + i) * *(matris + i);
    }
    printf("sum = %d", sum);
    printf("\n\n");
    printf("%d. hucre tamamlandi\n", index + 1);
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

    int expandedMatrisSizeOf = matris1Rw + matris2Rw - 1;
    int expandedMatrisSize = expandedMatrisSizeOf * expandedMatrisSizeOf;

    int **expandedMatris = matrisOlustur(expandedMatrisSizeOf);
    expandedMatrisDoldur(expandedMatris, matris1, expandedMatrisSize, matris1Size);
    matrisYazdirma(expandedMatris, expandedMatrisSizeOf);
    printf("-----------------------------------------\n");
    int *ptrExpandedMatris = *expandedMatris;
    int *temporaryMatris = (int *)malloc(sizeof(int) * matris2Size); //gecici olarak olusturulan her bir cozumMatris hucresindeki elemanı olusturmaya yardimci olacak matris.
    for (i = 0; i < cozumMatrisSizeOf; i++)
    {
        temporaryMatrisOlustur(temporaryMatris, ptrExpandedMatris, expandedMatrisSizeOf, matris2Rw, i, cozumMatrisSize);
        temporaryMatrisYazdir(temporaryMatris, matris2Rw);
        cozumMatrisDoldur(temporaryMatris, ptrMatris2, ptrCozumMatris, i, matris2Size);
    }

    matrisYazdirma(cozumMatris, cozumMatrisSize);

    matrisFree(expandedMatris, expandedMatrisSizeOf);
    free(temporaryMatris);
}
void expandedMatrisDoldur(int **expandedMatris, int **matris1, int expandedMatrisSize, int matris1Size)
{
    int matris1Rw = sqrt(matris1Size);
    int expandedMatrisSizeRw = sqrt(expandedMatrisSize);
    int beginingAmount = expandedMatrisSizeRw - matris1Rw;
    int beginFrom = beginingAmount / 2;
    //SILINEBILIR YORUM
    // printf("expandedMatrisSizeRw:%d\n beginingAmount: %d\n matris1size: %d\nbeginFrom: %d\n", expandedMatrisSizeRw, beginingAmount, matris1Rw, beginFrom);
    int i, j;
    for (i = beginFrom; i < matris1Rw + beginFrom; i++)
    {
        for (j = beginFrom; j < matris1Rw + beginFrom; j++)
        {
            *(*(expandedMatris + i) + j) = *(*(matris1 + i - beginFrom) + j - beginFrom);
        }
    }
    //SILINEBILIR YORUM
    // matrisYazdirma(expandedMatris, expandedMatrisSizeRw);
}