#include <stdio.h>
char *chrBul(char *str, char ch);

int main()
{

    char *arr = "yazilacak olan array";
    int aranan = 99;
    char *finded = chrBul(arr, aranan);
    printf("%d", arr - finded);
    return 0;
}
char *chrBul(char *str, char ch)
{
    int index = -1;
    int count = 0;
    // int flag = 1;
    while (*str != '\0')
    {
        if (*(str) == ch)
        {
            index = count;
            // flag = 0;
        }
        count++;
        str++;
    }
    str -= count;

    if (index = -1)
    {
        return NULL;
    }
    printf("%p and %p", str, str + index);
    char *deliver = (str + index);
    return deliver;
}
