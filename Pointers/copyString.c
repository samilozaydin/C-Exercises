#include <stdio.h>
void copy(char *dest, const char const *copy);

int main()
{

    char string1[10];
    char *string2 = "hello";
    char string3[] = "good day";
    char *string4;

    copy(string1, string2);
    copy(&string4[0], &string3[0]);
    puts(string1);
    puts(string4);
    return 0;
}
void copy(char *dest, const char const *copy)
{
    int i;
    for (i = 0; (dest[i] = copy[i]) != '\0'; i++)
    {
        ; /* do nothing in body */
    }
}