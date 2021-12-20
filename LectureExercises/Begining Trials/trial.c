#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *dosya = fopen("kullanicilar.dat", "w+");
    if (dosya == NULL)
    {
        printf("dosya acilamadi.");
        exit(1);
    }
    fputs("eklemelisinnnn\n", dosya);
    rewind(dosya);
    char take[10];
    fscanf(dosya, "%s", take);

    while (!feof(dosya))
    {
        printf("%s\n", take);
        fscanf(dosya, "%s", take);
    }
    fclose(dosya);
    printf("a");
    return 0;
}