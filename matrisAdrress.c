#include <stdio.h>

int main()
{

    char *ch[3] = {"hilal", "ali", "baci"};
    char **ptr;
    ptr = ch;

    printf("ch = %p\n", ch);
    printf("ch+1 = %p\n", ch + 1);

    printf("&ch = %p\n", &ch);
    printf("ptr = %p\n", ptr);
    printf("&ptr = %p\n", &ptr);

    printf("*ch = %p\n", *ch);
    printf("&*ch = %p\n", &*ch);
    printf("*(ch+1) = %p\n", *(ch + 1));

    printf("*ch = %p\n", ch[0]);
    printf("*ptr = %p\n", *ptr);

    printf("**ch = %p\n", **ch);
    printf("*ch = %c\n", **ch);

    return 0;
}