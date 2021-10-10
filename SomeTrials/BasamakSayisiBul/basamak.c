#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void numberCreator(int *);
int lengthOf(int *);
int howMuch(int *array);
void whichIsWhat(int *nums);

int main()
{

    int numbers[10];
    numberCreator(numbers);
    int count = howMuch(numbers);
    printf("\nThe number of 3 basamakli: %d\n", count);
    whichIsWhat(numbers);
    return 0;
}

void numberCreator(int *nums)
{
    srand(time(NULL));
    int length = 10;
    int i;
    for (i = 0; i < length; i++)
    {
        int a = rand() % 2000;
        nums[i] = a;
    }
}
int lengthOf(int *nums)
{
    return sizeof(nums) / sizeof(nums[0]);
}
int howMuch(int *array)
{
    int count = 0;
    int i;
    int length = 10;
    for (i = 0; i < length; i++)
    {

        if (array[i] > 99 && array[i] < 1000)
        {
            count++;
            printf("%d ", array[i]);
        }
        if (count % 5 == 0)
        {
            printf("\n");
        }
    }

    return count;
}
void whichIsWhat(int *nums)
{
    int length = 10;
    int i;
    int record = 0;
    int number;
    for (i = 0; i < length; i++)
    {
        record = 0;
        number = nums[i];
        while (number > 0)
        {
            number /= 10;
            record++;
        }
        printf("the number %d have %d basamak\n", nums[i], record);
    }
}