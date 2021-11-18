#include <stdio.h>
void func1(int *a);
void func2(int a[]);

int main()
{

    int i = 5;
    int *p = &i;

    printf("*(p++)= %p\n", p);
    printf("*(p++)= %d\n", *(p++));
    printf("*(p++)= %p\n", p);
    p--;
    printf("\n");
    printf("(*p)++= %p\n", p);
    printf("(*p)++= %d\n", (*p)++);
    printf("(*p)++= %p\n", p);
    printf("(*p)++= %d\n", (*p)++);
    printf("(*p)++= %p\n", p);
    int *q = &i;
    printf("i= %d\n", i);

    printf("\n*q++= %p\n", q);
    printf("*q++= %d\n", *q++);
    printf("*q++= %p\n", q);
    printf("*q++= %d\n", *q++);

    printf("i= %d\n", i);

    //  int ab[] = {0, 8, 69, 6};
    //  func1(ab);
    // func2(ab);

    return 0;
}
void func1(int *a)
{
    int ab = sizeof(a) / sizeof(a[0]);
    printf("%d\n", ab);
}
void func2(int a[])
{
    int ab = sizeof(a) / sizeof(a[0]);
    printf("%d\n", ab);
}