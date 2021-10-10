#include <stdio.h>

int toInverseNum(int);
int lengthCal(char *);
void toInverseString(char *);

int main()
{

    int num;
    int invNum;
    char string[50];

    printf("enter a number: ");
    scanf("%d", &num);
    invNum = toInverseNum(num);
    printf("%d\n", invNum);

    printf("enter a word: ");
    scanf("%s", string);
    toInverseString(string);

    int i;
    for (i = 0; i < 50; i++)
    {
        if (string[i] == '\0')
            break;

        printf("%c", string[i]);
    }
}

int toInverseNum(int number)
{
    int num;
    int temp = -1;
    while (number > 0)
    {
        temp = number % 10;
        number /= 10;
        num = temp + num * 10;
    }
    return num;
}
void toInverseString(char *array)
{
    char string[50];
    int length = lengthCal(array);

    int i;
    for (i = 0; i < length; i++)
    {
        string[i] = array[length - i - 1];
    }

    for (i = 0; i < length; i++)
    {
        array[i] = string[i];
    }
}
int lengthCal(char *array)
{
    int i;
    int length = 0;
    for (i = 0; i < 50; i++)
    {
        if (array[i] == '\0')
            break;

        length++;
    }
    return length;
}