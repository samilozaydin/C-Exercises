#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char *adi;
    char *soyadi;
    int *notlar;
} OGRENCI;

void ortalamaYaz(int);

int main()
{
    int ogrSayi;
    int i, j;
    printf("kac ogrenci: ");
    scanf("%d", &ogrSayi);
    OGRENCI *ogrenciler = malloc(ogrSayi * sizeof(OGRENCI));
    int miktar;

    for (i = 0; i < ogrSayi; i++)
    {
        ogrenciler[i].adi = (char *)malloc(30);
        printf("ogrenci adi: ");
        scanf("%d", ogrenciler[i].adi);
        ogrenciler[i].soyadi = (char *)malloc(30);
        printf("ogrenci soyadi: ");
        scanf("%d", ogrenciler[i].soyadi);

        printf("ogrenci not miktari: ");
        scanf("%d", &miktar);
        ogrenciler[i].notlar = (int *)malloc((miktar + 1) * sizeof(int));
        ogrenciler[0].notlar = miktar;
        for (j = 1; j <= miktar; j++)
        {
            printf("ogrenci notu : ");
            scanf("%d", &ogrenciler[i].notlar[j]);
        }
    }

    for (i = 0; i < ogrSayi; i++)
    {
        printf("adi: %s, soyadi: %s \n", ogrenciler[i].adi, ogrenciler[i].soyadi);
        for (j = 1; j < ogrenciler[i].notlar[0]; j++)
        {
            printf("%d. notu = %d", j, ogrenciler[i].notlar[j]);
        }
    }

    return 0;
}