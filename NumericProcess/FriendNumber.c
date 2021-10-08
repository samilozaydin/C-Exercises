#include <stdio.h>

int isPerfectNumber(int);

int main()
{

    int sayi;
    printf("sayi giriniz:");
    scanf("%d", &sayi);
    (isPerfectNumber(sayi)) ? printf("perfect") : printf("not");

    return 0;
}

int isPerfectNumber(int sayi)
{
    int temp;
    int sum = 0;

    int i;
    for (i = 1; i <= sayi / 2; i++)
    {
        if (sayi % i == 0)
        {
            sum += i;
        }
    }
    return ((sum == sayi) ? 1 : 0);
}