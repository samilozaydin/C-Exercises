#include <stdio.h>

void dosyaKarakterOku(char *dosyaYolu);
void dosyaKarakterYaz(char *dosyaYolu, char c);

int main(int argc, char *argv[])
{
    printf("%s\n", argv[0]);
    if (argc < 2)
    {
        printf("eksik arguman bulunmakta");
    }
    else if (argc == 2)
    {
        dosyaKarakterOku(argv[1]);
    }
    else if (argc == 3)
    {
        dosyaKarakterYaz(argv[1], argv[2][0]);
        dosyaKarakterOku(argv[1]);
    }
}

void dosyaKarakterOku(char *dosyaYolu)
{
    FILE *dosya;
    dosya = fopen(dosyaYolu, "r");
    if (dosya == NULL)
    {
        printf("Dosya Acilamadi");
        exit(1);
    }
    while (!feof(dosya))
    {
        putchar(fgetc(dosya));
    }
    fclose(dosya);
}
void dosyaKarakterYaz(char *dosyaYolu, char c)
{
    FILE *dosya;
    if ((dosya = fopen(dosyaYolu, "a")) == NULL)
    {
        exit(1);
    }
    fputc(c, dosya);

    fclose(dosya);
}