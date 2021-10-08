#include <stdio.h>

int uzunlukHesap(int);
int isArmstrong(int, int);
int usal(int, int);

int main()
{

    int sayi;
    int uzunluk;
    printf("Sayi gir");
    scanf("%d", &sayi);

    uzunluk = uzunlukHesap(sayi);

    if (isArmstrong(sayi, uzunluk))
    {
        printf("Armstrong");
    }
    else
    {
        printf("Armstrong degil");
    }

    return 0;
}

int uzunlukHesap(int sayi)
{
    int uzunluk = 0;
    while (sayi > 0)
    {
        sayi /= 10;
        uzunluk++;
    }
    return uzunluk;
}
int isArmstrong(int sayi, int uzunluk)
{
    int record = sayi;
    int temp = -1;
    int sum = 0;

    while (sayi > 0)
    {
        temp = sayi % 10;
        sayi /= 10;
        sum += usal(temp, uzunluk);
    }
    if (record == sum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int usal(int sayi, int uzunluk)
{
    int sonuc = 1;
    int i;
    for (i = 0; i < uzunluk; i++)
    {
        sonuc *= sayi;
    }
    return sonuc;
}