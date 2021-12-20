#include <stdio.h>
#include <stdlib.h>

void kopyala(char *des, char *src);

int main(int argc, char *argv[])
{
    FILE *dosya1, *dosya2;
    char c;

    if (argc != 3)
    {
        printf("eksik arguman");
        exit(1);
    }

    if ((dosya1 = fopen(argv[1], "w")) == NULL)
    {
        printf("Hedef acilmadi");
        exit(1);
    }

    if ((dosya2 = fopen(argv[2], "r")) == NULL)
    {
        printf("Hedef 2 acilmadi");
        exit(1);
    }
    while (!feof(dosya2))
    {
        c = fgetc(dosya2);
        fputc(c, dosya1);
    }

    return 0;
}
void kopyala(char *des, char *src)
{
}