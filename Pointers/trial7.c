#include <stdio.h>
void ters(char *str);
int main()
{
    char *arr = "yazilacak olan array";
    ters(arr);
    return 0;
}
void ters(char *str)
{
    int count = 0;
    int count2 = 0;
    int i;
    for (i = 0; *(str + i) != '\0'; i++)
    {
        count++;
    }
    char *ch2;
    for (i = count; i >= 0; i--)
    {
        *(ch2 + count2) = *(str + count);
        count--;
        count2++;
    }
    for (i = 0; i < count2; i++)
    {
        printf("%c", *(ch2 + i));
    }
}
