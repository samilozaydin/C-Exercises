#include <stdio.h>
#include <windows.h>

int main()
{

    int delay = 1000;
    int hour, minute, second;
    printf("Please, set a particular time: ");
    scanf("%d%d%d", &hour, &minute, &second);

    if (hour > 23 || minute > 60 || second > 60)
    {
        printf("Wrong input is entered\n");
        exit(0);
    }

    while (1)
    {
        second++;
        if (second > 59)
        {
            minute++;
            second = 0;
        }
        if (minute > 59)
        {
            hour++;
            minute = 0;
        }
        if (hour > 23)
        {
            hour = 0;
        }
        printf("\nClock:");
        printf("\n %02d:%02d:%02d", hour, minute, second);
        Sleep(delay);
    }

    return 0;
}