#include <stdlib.h>
#include <stdio.h>

int main()
{

    FILE *dosya = fopen("exercise4.txt", "r+");
    char yazi;
    int satir = 1;
    int kelime = 1;
    if (dosya == NULL)
    {
        printf("kapat");
        exit(1);
    }
    else
    {
        while (!feof(dosya))
        {
            fscanf(dosya, "%c", &yazi);
            if (yazi == ' ')
            {
                kelime++;
            }
            else if (yazi == '\n')
            {
                satir++;
                if (fscanf(dosya, "%c", &yazi))
                    kelime++;
            }
        }
    }
    printf("kelime :%d satir: %d", kelime, satir);
    fclose(dosya);
    return 0;
}