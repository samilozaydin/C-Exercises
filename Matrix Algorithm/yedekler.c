//matris olusturma icin olusturulan kod parcasi
int **matris3 = (int **)calloc(matris3Size, sizeof(int *)); //Her satir ayri ayri free edilmeli
int i, j;
int b = 20;
for (i = 0; i < matris3Size; i++)
{
    *(matris3 + i) = (int *)calloc(matris3Size, sizeof(int));
    for (j = 0; j < matris3Size; j++)
    {
        *(*(matris3 + i) + j) = b++;
    }
}