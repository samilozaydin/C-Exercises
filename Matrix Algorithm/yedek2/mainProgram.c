#include <stdio.h>
#include <math.h>
#include "matrisoperations.h"
int inputKontrol(int matris1Size, int matris2Size, int islemTipi);

extern int CozumMatrisSize;

int main()
{
    int matris1Size;
    int matris2Size;
    int islemTipi;
    do
    {
        printf("-----------------------------------------\n");
        printf("1.Matrisin sutun buyuklugunu giriniz: ");
        scanf("%d", &matris1Size);
        printf("2.Matrisin sutun buyuklugunu giriniz: ");
        scanf("%d", &matris2Size);
        printf("Islem tipini giriniz:");
        scanf("%d", &islemTipi);
        printf("-----------------------------------------\n");
    } while (inputKontrol(matris1Size, matris2Size, islemTipi));

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
int inputKontrol(int matris1Size, int matris2Size, int islemTipi)
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
        printf("matrislerin boyutu 3 ve 3'ten buyuk olmalidir\n");
        return 1;
    }
    if ((matris1Size % 2 == 0) && (matris2Size % 2 == 0))
    {
        printf("matrislerin boyutlari tek sayi olmalidir\n");
        return 1;
    }
    return 0;
}