#include <stdio.h>

void getir(char *array1, char *array2);

int main()
{

    char array[] = "kocaeli";
    char array2[] = "sakarya";
    getir(array, array2);
    int i;

    return 0;
}

void getir(char *array1, char *array2)
{
    int i;
    int j;
    char array[20];
    int x = 0;
    for (i = 0; *(array1 + i) != '\0'; i++)
    {
        for (j = 0; *(array2 + j) != '\0'; j++)
        {
            if (*(array1 + i) == *(array2 + j))
            {
                break;
            }
            if (*(array2 + j + 1) == '\0')
            {
                array[x] == *(array1 + i);
                x++;
            }
        }
    }

    for (i = 0; i < x; i++)
    {
        printf("%c", array[i]);
    }
}