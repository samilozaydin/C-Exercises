#include <stdio.h>

struct person
{
    int age;
    char *name;
};
int main()
{

    struct person person1 = {1, "ali"};
    struct person *p = &person1;

    printf("%p\n", p);
    printf("%p\n", p.age);

    printf("%p\n", &person1.name);
    printf("%p\n", &person1.age);

    printf("%d\n", *(p).age);

    return 0;
}