#include <stdlib.h>
#include <stdio.h>
char **fonk(char *str, char c);
void fonk2(char *str);

int Size = 0;
int main()
{
    char str[] = "karakter";
    char **yakala = fonk(str, 'a');
    fonk2(str);

    free(yakala);
    return 0;
}
void fonk2(char *str)
{
    int i;
    for (i = 0; *(str + i) != '\0'; i++)
    {
        printf("%d. karakter '%c'adresi: %p \n", i + 1, *(str + i), str + i);
    }
}
char **fonk(char *str, char c)
{
    int i;
    int size = 1;
    char **point;

    point = (char **)calloc(1, sizeof(char *));

    for (i = 0; i < *(str + i) != '\0'; i++)
    {
        if (*(str + i) - c == 0)
        {
            *(point + size - 1) = str + i;
            size++;
            point = realloc(point, sizeof(char *) * size);
        }
    }

    for (i = 0; i < size - 1; i++)
    {
        printf("%d.karakter adresi: %p\n", *(point + i) - str, *(point + i));
    }
    Size = size;
    return point;
}