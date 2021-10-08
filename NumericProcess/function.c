#include <stdio.h>
#include "function.h"

int divideAndSum(int number)
{
    int sum = 0;
    int i;
    for (i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}
int isFriendNumber(int sum1, int sum2, int num1, int num2)
{
    return ((sum1 == num2 && sum2 == num1) ? 1 : 0);
}
int isStrongNumber(int number)
{
    int record = number;
    int temp = -1;
    int sum = 0;

    while (number > 0)
    {
        temp = (number % 10);
        number /= 10;
        sum += fact(temp);
    }
    return (record == sum ? 1 : 0);
}
int fact(int number)
{
    int i;
    int count = 1;
    for (i = 1; i <= number; i++)
    {
        count *= i;
    }
    return count;
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