#include <stdio.h>

int poww(int sayi)
{
    int tut = 1;
    while (sayi > 0)
    {
        tut *= 10;
        sayi--;
    }
    return tut;
}

int main()
{

    int sayi;
    printf("sayi gir:");
    scanf("%d", &sayi);

    int uzunluk = 0;
    int i;
    while (sayi > 0)
    {
        sayi /= 10;
        uzunluk++;
    }
    for (i = 0; i < uzunluk / 2; i++)
    {
        if ((sayi % (10 * poww(i))) != (sayi % (10 * poww((uzunluk - 1) - i))))
        {
            printf("palindrome degil.");
            break;
        }
    }

    return 0;
}
