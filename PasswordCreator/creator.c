#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void passwordCreator(char *array);
void character(char *array, int num, int index);

int main()
{
    char password[20];
    passwordCreator(password);

    int i;
    for (i = 0; i < 20; i++)
    {
        printf("%c", password[i]);
    }

    return 0;
}
void passwordCreator(char *array)
{
    srand(time(NULL));
    int num;
    int i;
    for (i = 0; i < 20; i++)
    {
        num = rand() % 3;
        character(array, num, i);
    }
}
void character(char *array, int num, int index)
{
    char c;
    if (num == 0)
    {
        num = rand();
        num = (num % 10) + 48;
        c = num;
        array[index] = c;
    }
    if (num == 1)
    {
        num = rand();
        num = (num % 25) + 65;
        c = num;
        array[index] = c;
    }
    if (num == 2)
    {
        num = rand();
        num = (num % 25) + 97;
        c = num;
        array[index] = c;
    }
}
