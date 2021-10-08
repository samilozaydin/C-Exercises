#include <stdio.h>

int isStrongNumber(int);
int fact(int);

int main()
{

    int number;
    printf("enter number :");
    scanf("%d", &number);

    if (isStrongNumber(number))
    {
        printf("Strong number");
    }
    else
    {
        printf("not strong number");
    }

    return 0;
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