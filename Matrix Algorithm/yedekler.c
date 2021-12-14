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

//islem tipi 0 için ilerlenen bir bolum
for (j = 0; j < matris1Rw; j++)
{
    counter = 0;
    for (k = 0 + position; k < matris2Rw + position; k++)
    {
        sum = sum + *(*(matris1 + j) + k) * *(*(matris2 + j) + k);
    }
    if (counter >= matris2Rw - 1)
    {
        position++;
        // if (position + matris2Rw ){

        //  }
        j = j - matris2Rw + 1;
    }
    counter++;
}
//Islem tipi 0 icin olusturulmus, temporaryMatrisOlustur fonksiyonun bulundugu mekana yerlestirilmeden onceki kod
for (j = 0; j < matris2Size; j++)
{
    *(temporaryMatris + j) = *(ptrMatris1 + i + j + (matris1Rw - matris2Rw) * (j / matris2Rw));
}

//Islem tipi 0 icin cozum matrisinin icindeki elemanlarin tek tek toplamini hesaplayan zimbirtiydi. Fonksiyonun tamamini koyacagim. Hali hazirda kullanilmaya devam ediliyor.
void cozumMatrisDoldur(int *tempMatris, int *matris, int *cozumMatris, int index, int size)
{
    int sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d * %d = %d \n", *(tempMatris + i), *(matris + i), *(tempMatris + i) * *(matris + i));
        sum += *(tempMatris + i) * *(matris + i);
    }
    printf("sum = %d", sum);
    printf("\n\n");
    printf("%d. hucre tamamlandi\n", index + 1);
    *(cozumMatris + index) = sum;
}
//Bu alan cok fazla oynanmamis temporarymatrisolusturma fonksiyonu. Degisen seyler cozumMatrisRw eklenmesi ve (position / cozumMatrisRw) kısmında matris2Rw yerine eklenmesi. Duruma gore buradan oyna.
void temporaryMatrisOlustur(int *matris, int *ptrMatris1, int matris1Rw, int matris2Rw, int position, int cozumMatrisRw)
{
    int j;
    int size = matris2Rw * matris2Rw;
    for (j = 0; j < size; j++)
    {
        *(matris + j) = *(ptrMatris1 + position + j + (matris1Rw - matris2Rw) * (j / matris2Rw) + (position / cozumMatrisRw) * (matris1Rw - matris2Rw));
    }
}