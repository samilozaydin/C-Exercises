#include <stdio.h>
#include <string.h>

void maxMinChar(char sentence[], int size);
int findMaxIndex(int array[], int size);
int findMinIndex(int array[], int size);

int main()
{
    char string[] = "hello world, welcome to the java programming lesson";
    int i, j, min, max, length = strlen(string);
    char minChar = string[0], maxChar = string[0];
    int freq[length];

    return 0;
}

void maxMinChar(char sentence[], int size)
{

    for (i = 0; i < size; i++)
    {
        freq[i] = 1;
        for (j = i + 1; j < size; j++)
        {
            if (sentence[i] == sentence[j] && sentence[i] != ' ' && sentence[i] != '0')
            {
                freq[i]++;

                string[j] = '0';
            }
        }
    }

    return 0;
}

int findMinIndex(int array[], int size)
{
    for (i = 0; i < size; i++)
    {
        freq[i] = 1;
        for (j = i + 1; j < size; j++)
        {
            if (array[i] == array[j] && array[i] != ' ' && array[i] != '0')
            {
                freq[i]++;

                //Set string[j] to 0 to avoid printing visited character
                array[j] = ' ';
            }
        }
    }

    min = max = freq[0];
    for (i = 0; i < size; i++)
    {

        //If min is greater than frequency of a character
        //then, store frequency in min and corresponding character in minChar
        if (min > freq[i] && freq[i] != '0')
        {
            min = freq[i];
            minChar = string[i];
        }
    }

    int findMaxIndex(int[] array, size)
    {

        min = max = freq[0];
        for (i = 0; i < size; i++)
        {

            if (max < freq[i])
            {
                max = freq[i];
                maxCh = sentence[i];
            }
        }

        printf("Maximum occurring character: %c", maxCh);
    }