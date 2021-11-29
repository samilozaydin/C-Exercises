#include <stdio.h>
void tersMetin(char *);
int main()
{
    char arr[] = "Fatih sultan";

    tersMetin(arr);
    printf("%s", arr);
    return 0;
}
void tersMetin(char *arr)
{
    char *p = arr;
    char temp;
    int count;

    for (; *p != '\0'; p++)
    {
        ;
    }
    p--;
    count = p - arr + 1;

    int i;
    for (i = 0; i < count / 2; i++)
    {
        temp = *p;
        *p = *arr;
        *arr = temp;

        arr++;
        p--;
    }
}