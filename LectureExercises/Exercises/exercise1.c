#include <stdlib.h>
#include <stdio.h>
void yazdir(FILE *dosya);
void dosyayaYazdir(FILE *dosya, char c);

int main(int argc, char *argv[])
{

    char *p;
    p = argv[1];
    printf("%s \n", p);
    FILE *dosya = fopen(p, "r+");
    printf("%p", dosya);
    if (dosya == NULL)
    {
        printf("kapatildi.");
        exit(1);
    }
    else
    {
        if (argc == 2)
            yazdir(dosya);
        if (argc == 3)
            dosyayaYazdir(dosya, argv[2][0]);
    }
    fclose(dosya);
    return 0;
}
void yazdir(FILE *dosya)
{
    char ch;
    rewind(dosya);
    while (!feof(dosya))
    {
        fscanf(dosya, "%c", ch);
        printf("%c\n", ch);
    }
}
void dosyayaYazdir(FILE *dosya, char c)
{
    fprintf(dosya, "%c", c);
}