#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char *ch[3] = {"hello", "world00000", "wonderful"};
    char ar[2] = {'a', 'b'};
    int arr[2] = {6, 8};
    int *arr2;
    char **ptr = ch;
    printf("ptr %p\n", ptr);
    printf("&ptr %p\n", &ptr);

    printf("arr2 %p\n", arr2);
    printf("&arr2 %p\n", &arr2);

    printf("&arr[0] %p\n", &arr);
    printf("arr[0] %p\n", arr);

    printf("&ar[0] %p\n", &ar);
    printf("ar[0] %p\n", ar);

    printf("ch[0]%p\n", ch);
    printf("&ch[0][0] = %p\n", (*(ch) + 0));
    printf("&ch[0][1] = %p\n", (*(ch) + 1));
    printf("&ch[0][2] = %p\n", (*(ch) + 2));
    printf("&ch[0][3] = %p\n", (*(ch) + 3));
    printf("&ch[0][4] = %p\n", (*(ch) + 4));

    printf("*****************\n");
    printf("ch[1]%p\n", ch + 1);
    printf("&ch[1][0] = %p\n", (*(ch + 1) + 0));
    printf("&ch[1][1] = %p\n", (*(ch + 1) + 1));
    printf("&ch[1][2] = %p\n", (*(ch + 1) + 2));

    printf("*****************\n");
    printf("ch[2]%p\n", ch + 2);
    printf("ch[2][0] = %p\n", (*(ch + 2) + 0));
    printf("ch[2][1] = %p\n", (*(ch + 2) + 1));
    printf("ch[2][6] = %p\n", (*(ch + 2) + 6));

    return EXIT_SUCCESS;
}