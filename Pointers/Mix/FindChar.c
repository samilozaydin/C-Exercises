#include <stdio.h>
char *chrBul(char *str, char ch);

int main()
{

    char arr[] = "yazilacak olan array";
    int aranan = 99;
    char *finded = chrBul(arr, aranan);
    printf("%c", *finded);
    return 0;
}
char *chrBul(char *str, char ch)
{
    int index = -1;
    int count = 0;
    while (*str != '\0')
    {
        if (*(str) == ch)
        {
            index = count;
        }
        count++;
        str++;
    }
    str += index - count;

    if (index == -1)
    {
        return NULL;
    }

    return str;
}
