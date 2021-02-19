#include <stdio.h>
#include <stdlib.h>

void bubblesort(int dizi[],int uzunluk)
{
    int i,j;
    int gecici;
    for(i = 0; i < uzunluk; i++)
    {
        for(j = 1; j<uzunluk-i; j++)
        {
            if(dizi[j-1] > dizi[j])
            {
                gecici = dizi[j-1];
                dizi[j-1] = dizi[j];
                dizi[j] = gecici;
            }
        }
    }


}

int main()
{
    int array[30];
    int diziuzunluk,i;
    printf("Lutfen uzunluk giriniz:");
    scanf("%d",&diziuzunluk);
    printf("Lutfen siralamak istediginiz sayilari giriniz:");
    for(i=0;i<diziuzunluk;i++)
    {
        scanf("%d",&array[i]);
    }

    bubblesort(array,diziuzunluk);

    for(i=0;i<diziuzunluk;i++)
    {
        printf("%d ",array[i]);
    }
}






