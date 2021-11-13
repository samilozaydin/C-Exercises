#include <stdio.h>
void changeNum(int *num, int wanNum);

int main()
{
    int num = 0;
    int *p = &num;
    int a[3] = {1, 2, 3};
    printf("number is : %d\n", num);
    changeNum(&num, 35);
    printf("number is : %d\n", num);

    changeNum(a, 70);
    printf("number is : %d\n", *(a));

    changeNum(p, 20);
    printf("number is : %d\n", num);

    return 0;
}
void changeNum(int *num, int wanNum)
{

    *num = wanNum;
}