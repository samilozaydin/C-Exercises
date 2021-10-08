#include <stdio.h>

int divideAndSum(int number);
int isFriendNumber(int sum1, int sum2, int num1, int num2);

int main()
{

    int num1, num2;
    printf("enter two number : ");
    scanf("%d%d", &num1, &num2);

    int sum1 = divideAndSum(num1);
    int sum2 = divideAndSum(num2);

    if (isFriendNumber(sum1, sum2, num1, num2))
    {
        printf("friend");
    }
    else
    {
        printf("not friend");
    }
    return 0;
}
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