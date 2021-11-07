#include <stdio.h>
int factorial(int *num);
int factorialRecursion(int *num);

int main()
{
    int num;
    printf("enter a number that will be calculated: ");
    scanf("%d", &num);

    printf("\nCalculated number is: %d\n", factorial(&num));
    printf("\nCalculated number with recursion is: %d", factorial(&num));

    return 0;
}

int factorial(int *num)
{
    int base = 1;
    int i;
    for (i = 1; i <= *num; i++)
    {
        base *= i;
    }
    return base;
}
int factorialRecursion(int *num)
{
    if (*num == 1)
    {
        return 1;
    }
    else if (*num < 1)
    {
        return -1;
    }
    return *num * factorialRecursion(*num - 1);
}