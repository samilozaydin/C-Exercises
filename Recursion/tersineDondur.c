#include <stdio.h>
int ters(int num, int tersi);
int ters2(int num);
int ters3(int num);

int main()
{
    //printf("%d", ters(123, 0));
    printf("%d", ters2(345));
    printf("%d", ters3(345));

    return 0;
}

int ters(int num, int tersi)
{
    if (num == 0)
    {
        return tersi;
    }
    return ters(num / 10, tersi * 10 + num % 10);
}
int ters2(int num)
{
    int b = num;
    if (num < 9)
    {
        return num;
    }
    int a = 1;
    while (b / (a * 10) > 0)
    {
        a *= 10;
    }
    return (num % 10) * a + ters2(num / 10);
}
int ters3(int num)
{
    if (num < 10)
    {
        return num;
    }
    int us = 0;
    int tempt = num;
    while (tempt > 0)
    {
        tempt /= 10;
        us++;
    }
    us--;

    return (num % 10) * pow(10, us) + ters3(num / 10);
}
/*
int ters4(int num, int rev){
    if(num ==0){
        return num;
    }
    return ters4(num/10,num%10+rev*10);
}
*/
