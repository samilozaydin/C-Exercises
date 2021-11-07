#include <stdio.h>

int main()
{
    char arr[] = "kral";
    int size = sizeof(arr) / sizeof(arr[0]);
    char *p;
    reverseString(arr, size - 2, p);
    printf("%c", *(p - 2));
    return 0;
}

void reverseString(char *sentence, int size, char *rev)
{

    if ((*sentence + size) == '\0')
    {
        size--;
    }
    if (size < 0)
    {
        return;
    }
    *(rev) = *(sentence + size);
    printf("%c and %p \n", *rev, rev);
    rev++;
    if (size == 0)
    {
        *(rev) = '\0';
    }
    return reverseString(sentence, size - 1, rev);
}