#include <stdio.h>
void incrementLocal();
void decrementStatic();

int main()
{

    int i;
    for (i = 0; i < 3; i++)
    {
        incrementLocal();
    }
    for (i = 0; i < 3; i++)
    {
        decrementStatic();
    }
}

void incrementLocal()
{
    int num = 25;

    num++;
    printf("%d\n", num);
}
void decrementStatic()
{
    static int num = 30;
    num--;
    printf("%d\n", num);
}