#include <stdlib.h>
#include <stdio.h>
int **matrisOlustur(int size);
void matrisFree(int **matris, int size);
void matrisYazdirma(int **matris, int size);
int **olustur(int size);

int main()
{

    int **matris = matrisOlustur(3);
    //matrisYazdirma(matris, 3);
    matrisFree(matris, 3);
    return 0;
}
void matrisYazdirma(int **matris, int size)
{
    int i, j;
    for (i = 0; i < size; i++) //SIL
    {
        for (j = 0; j < size; j++)
        {
            printf("%d\t", *(*(matris + i) + j));
        }
        printf("\n");
    }
    printf("-----------------------------------------");
}
void matrisFree(int **matris, int size)
{
    int i;
    free(*matris);
    free(matris);
}
int **matrisOlustur(int size)
{
    int **matris3 = (int **)(malloc(size * sizeof(int *))); //Sadece matris[0] free edilse yeterli
    printf("*matris3 %p\n", *matris3);
    printf("*matris3+1 %p\n", *(matris3 + 1));
    printf("*matris3+2 %p\n", *(matris3 + 2));
    *(matris3) = (int *)malloc(size * size * sizeof(int));
    int i, j;
    int b = 20;

    for (i = 1; i < size; i++)
    {
        *(matris3 + i) = *matris3 + i * size;
        /*for (j = 0; j < size; j++)
        {
            printf("%d ", b);
            *(*(matris3 + i) + j) = b++;
        }
        printf("\n");*/
    }
    printf("\n");
    printf("*matris3 %p\n", *matris3);
    printf("*matris3+1 %p\n", *(matris3 + 1));
    printf("*matris3+2 %p\n", *(matris3 + 2));
    return matris3;
}
int **olustur(int size)
{
    int **matrix = (int **)malloc(size * sizeof(int *));
    matrix[0] = (int *)malloc(size * size * sizeof(int));
    printf("*matrix %p\n", *matrix);
    printf("*matrix+1 %p\n", *(matrix + 1));
    printf("*matrix+2 %p\n", *(matrix + 2));

    for (int i = 1; i < size; i++)
    {
        matrix[i] = matrix[0] + i * size;
    }
    printf("*matrix %p\n", *matrix);
    printf("*matrix+1 %p\n", *(matrix + 1));
    printf("*matrix+2 %p\n", *(matrix + 2));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    return matrix;
}