#include <stdio.h>
void func1(int const *p);

int main()
{

    int a = 5;
    int *const p = &a;
    //int b = 10;

    printf("%p\n", p);
    printf("%d\n", *p + 1);
    //*p++;
    printf("%p\n", p);
    printf("%d\n", *p);

    // p = &b;
    //  printf("%p\n", p);
    //  printf("%d\n", *p);
    //  p += 5;
    //  printf("%p\n", p);
    //func1(p);
    return 0;
}
void func1(int const *p)
{
    p += 5;
    // printf("%p\n", p);
}