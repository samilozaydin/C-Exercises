/*
* @file mainProgram.c
* @description This program is a matrix algorithm.
* @assignment Project 1
* @date 11.12.2021
* @author Samil Bilal OZAYDIN samilbilal.ozaydin@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <math.h>
#include "matrisoperations.h"
#include <stdlib.h>
#include <time.h>

int inputKontrol(int, int, int, int);
int sendParameter(char **, int, int);

extern int CozumMatrisSize;

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        printf("Program eksik arguman icerdiginden calisamaz");
        exit(1);
    }
    int matris1Size = sendParameter(argv, argc, 1);
    int matris2Size = sendParameter(argv, argc, 2);
    int islemTipi = sendParameter(argv, argc, 3);
    int seed = sendParameter(argv, argc, 4);
    while (inputKontrol(matris1Size, matris2Size, islemTipi, seed))
    {
        printf("\nProgram sonlandirildi.\n");
        printf("-----------------------------------------\n");
        exit(1);
    }
    srand(seed);

    int **matris1 = matrisOlustur(matris1Size);
    int **matris2 = matrisOlustur(matris2Size);
    matrisDoldur(matris1, matris1Size);
    matrisDoldur(matris2, matris2Size);
    printf("Matris1 elemanlari:\n");
    matrisYazdirma(matris1, matris1Size);
    printf("\n");
    printf("Matris2 elemanlari:\n");
    matrisYazdirma(matris2, matris2Size);

    int **cozumMatris = operasyon1(matris1, matris2, islemTipi, matris1Size * matris1Size, matris2Size * matris2Size);
    printf("\n");
    printf("Cozum matrisi elemanlari:\n");
    matrisYazdirma(cozumMatris, CozumMatrisSize);

    matrisFree(cozumMatris, CozumMatrisSize);
    matrisFree(matris1, matris1Size);
    matrisFree(matris2, matris2Size);
    return 0;
}
int inputKontrol(int matris1Size, int matris2Size, int islemTipi, int seed)
{
    if (!((islemTipi >= 0) && (islemTipi <= 1)))
    {
        printf("islem tipi 0 veya 1 olabilir\n");
        return 1;
    }
    if (matris1Size < matris2Size)
    {
        printf("matris1 matris2'den buyuk olmalidir.\n");
        return 1;
    }
    if ((matris1Size < 3) && (matris2Size < 3))
    {
        printf("matrislerin boyutu 3 ve 3'ten buyuk olmalidir veya harf girilmemelidir\n");
        return 1;
    }
    if ((matris1Size % 2 == 0) || (matris2Size % 2 == 0))
    {
        printf("matrislerin boyutlari tek sayi olmalidir\n");
        return 1;
    }
    if (seed == -1)
    {
        printf("seed -1 veya sayi disinda bir sey olamaz.");
        return 1;
    }
    return 0;
}
int sendParameter(char **arr, int size, int index)
{
    int i;
    int send = 0;
    for (i = 0; *(*(arr + index) + i) != '\0'; i++)
    {
        if (*(*(arr + index) + i) - '0' <= ('9' - '0') && *(*(arr + index) + i) - '0' <= ('9' - '0') >= 0)
        {
            send = send * 10 + (int)(*(*(arr + index) + i) - '0');
        }
        else
        {
            return -1;
        }
    }
    return send;
}