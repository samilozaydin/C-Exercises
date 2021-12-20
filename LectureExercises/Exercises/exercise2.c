#include <stdio.h>
#include <stdlib.h>
void say(char *des, int *frekans, int size);

int main(int argc, char *argv[])
{
    int frekans[26] = {0};
    if (argc == 2)
    {
        say(argv[1], frekans, 26);
    }

    return 0;
}
void say(char *des, int *frekans, int size)
{
    char ch;
    FILE *dosya;
    if (dosya = fopen(des, "r") == NULL)
    {
        printf("dosya acilmadi");
        exit(1);
    }
    else
    {
        while (!(feof(dosya)))
        {
            fscanf(dosya, "%c", ch);
            frekans[ch - 'a']++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%c'den su kadar var :%d\n", (char)('a' + i), frekans[i]);
    }

    fclose(dosya);
}