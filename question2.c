#include <stdio.h>
#include <string.h>

void tersMetin(char *str)
{

    char *baslangic;
    char *bitis;
    char ch;
    int x = strlen(str);

    baslangic = str;
    bitis = str;

    for (int y = 0; y < x - 1; y++)
        bitis++;

    for (int y = 0; y < x / 2; y++)
    {

        ch = *bitis;
        *bitis = *baslangic;
        *baslangic = ch;

        baslangic++;
        bitis--;
    }
}

int main()
{
    char str[100] = "Fatih sultan";
    printf("Enter a string: %s\n", str);
    tersMetin(str);
    printf("Reverse of the string: %s\n", str);

    return 0;
}