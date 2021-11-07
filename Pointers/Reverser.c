#include <stdio.h>
void ters(char *str);
int main()
{
    char arr[] = "yazilacak olan array";
    ters(arr);
    puts(arr);
    return 0;
}
void ters(char *str)
{
    char *pReverse = str;
    char *pOriginal = str;
    char olustur[100];
    while (*str != '\0')
    {
        str++;
        pReverse++;
    }
    int i = 0;
    while ((int)(pReverse - pOriginal) >= 0)
    {
        olustur[i] = *(pReverse);
        pReverse--;
        i++;
    }
}
