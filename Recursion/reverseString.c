#include <stdio.h>

int main()
{
    char arr[] = "kral";
    int size = sizeof(arr) / sizeof(arr[0]);
    char arr2[10];
    reverseString(arr, size, arr2);
    printf("\n%s bbb", arr2);
    return 0;
}

void reverseString(char *sentence, int size, char *rev)
{
    if (size < 2)
        return;
    *rev++ = *(sentence + (size - 2));
    if (size == 2)
        *(rev) = '\0';

    return reverseString(sentence, size - 1, rev);
}