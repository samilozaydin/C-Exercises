#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void func(int a[], int *b);

struct xxx
{
    int id;
    char name;
    long id2;
    char c;
    long per;
};

int main()
{
    /* printf("%d\n", (int)sizeof(int));
    char p[10];
    char p2[10];
    char *p3;
    char *arr[3] = {"hello", "abba", "kappappa"};
    printf("arr = %p \n", arr);
    printf("arr = %p \n", arr + 1);
    printf("*arr = %p \n", *arr);
    printf("**arr = %c \n", **arr);

    printf("*(arr+1) = %p \n", *(arr + 1));
    printf("**(arr+1) = %c \n", **(arr + 1));

    printf("*(arr+2) = %p \n", *(arr + 2));
    printf("**(arr+2) = %c \n", **(arr + 2));
*/

    int a[5] = {4, 8, 9, 3, 5};
    int *b = a;
    ++*b;
    printf("%d %d %d", a[0], a[1], *b);

    /*int *arr[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = (int *)malloc(sizeof(int));
        *arr[i] = i;
    }
    printf("adres : %p\n", *(arr));
    printf("adres : %p\n", *(arr + 1));
    printf("adres : %p\n", *(arr + 2));
    printf("adres : %p\n", *(arr + 3));
    fgets()
    for (int i = 0; i < 5; i++)
    {
        free(arr[i]);
    }*/
    /*  int a1 = 1;

    printf("%d\n", a1);
    a1 = a1 << 2;
    printf("%d\n", a1);
    printf("%08u\n", 1 << 5);

    int a[10] = {0};
    printf("%d\n", sizeof(a));
    printf("basladi\n");*/
    // gets(p2);
    //  scanf("%s", p2);

    // printf("%s\n", p2);
    //  puts(p2);
    return 0;
}
/*void func(int a[], int *b)
{

    int size1 = sizeof(a) / sizeof(a[0]);
    int size2 = sizeof(b) / sizeof(b[0]);

    printf("%d\n", size1);
    printf("%d\n", size2);
}*/