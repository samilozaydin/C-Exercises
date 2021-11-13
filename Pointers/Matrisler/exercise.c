#include <stdio.h>
void maxMinChar(char sentence[], int size);
int findMinIndex(int array[], int size);
int findMaxIndex(int array[], int size);

int main()
{

    char deneme[] = "araba";
    maxMinChar(deneme, sizeof(deneme));
    return 0;
}

void maxMinChar(char sentence[], int size)
{
    int frekans[58] = {0};
    int i;
    for (i = 0; i < size; i++)
    {
        int charNum = sentence[i];
        printf("%d\n", charNum);
        if (charNum > 96)
        {
            frekans[charNum - 97]++;
        }
        else
        {
            frekans[charNum - 65 + 29]++;
        }
    }

    int maxIndeks = findMaxIndex(frekans, 58);
    int minIndeks = findMinIndex(frekans, 58);

    char max;
    char min;
    if (maxIndeks < 29)
    {
        max = maxIndeks + 97;
    }
    else
    {
        max = maxIndeks + 65;
    }
    if (minIndeks < 29)
    {
        min = minIndeks + 97;
    }
    else
    {
        min = minIndeks + 65;
    }
    printf("max character %c", max);
    printf("min character %c", min);
}
int findMinIndex(int array[], int size)
{
    int i;
    int temp = array[0];
    int indeks = 0;

    for (i = 0; i < size; i++)
    {
        if (array[i] < temp && array[i] != 0)
        {
            temp = array[i];
            indeks = i;
        }
    }

    return indeks;
}
int findMaxIndex(int array[], int size)
{
    int i;
    int temp = array[0];
    int indeks = 0;
    for (i = 0; i < size; i++)
    {
        if (array[i] > temp)
        {
            temp = array[i];
            indeks = i;
        }
    }

    return indeks;
}