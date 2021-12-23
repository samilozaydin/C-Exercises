#include <stdio.h>
#include <stdlib.h>
void oku(char *des1, char *des2);

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf("kapan");
        exit(1);
    }
    else
    {
        oku(argv[1], argv[2]);
    }
}
void oku(char *des1, char *des2)
{
    FILE *dosya1;
    FILE *dosya2;
    char p;
    if ((dosya1 = fopen(des1, "w+")) && (dosya2 = fopen(des2, "r")) == NULL)
    {
        printf("kapattim\n");
        exit(1);
    }
    else
    {
        while (!(feof(dosya2)))
        {
            fscanf(dosya2, "%c", &p);
            fprintf(dosya1, "%c", p);
        }
    }
    fclose(dosya1);
    fclose(dosya2);
}