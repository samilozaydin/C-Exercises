#include <stdio.h>

enum status
{
    true = 1,
    false = 0
};

typedef enum
{
    first,
    second,
    third
} order;

int main()
{

    enum status stat = false;
    order one = first;

    if (stat == one)
    {
        printf("This is so true");
    }
    else
    {
        printf("This is not true");
    }

    return 0;
}