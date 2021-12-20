#include <stdlib.h>
#include <stdio.h>

int main()
{

    int num;
    char ch[] = {'0', 'd', 'a', '\0'};
    FILE *dosya;

    if ((dosya = fopen("gecici.txt", "r+")) == NULL)
    {
        printf("calismaz.  \n");
        exit(1);
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {

            fwrite(ch, sizeof(char), 4, dosya);
        }
        rewind(dosya);
        for (int i = 0; i < 5; i++)
        {
            fread(ch, sizeof(char), 4, dosya);
            printf("%s\n", ch);
        }
    }
    fclose(dosya);
    return 0;
}