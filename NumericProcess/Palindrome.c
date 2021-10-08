#include <stdio.h>

int isPalindrome(int sayi, int sayiTers);
int tersCevir(int sayi);

int main()
{

    int sayi;
    int sayiTers;
    printf("sayi gir:");
    scanf("%d", &sayi);
    sayiTers = tersCevir(sayi);
    if (isPalindrome(sayi, sayiTers))
    {
        printf("palindrome");
    }
    else
    {
        printf("degil");
    }

    return 0;
}

int isPalindrome(int sayi, int sayiTers)
{
    return ((sayi == sayiTers) ? 1 : 0);
}
int tersCevir(int sayi)
{
    int sum = 0;
    int temp;
    while (sayi > 0)
    {
        temp = sayi % 10;
        sayi /= 10;
        sum = temp + 10 * sum;
    }
    return sum;
}