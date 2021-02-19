#include <stdio.h>
#include <stdlib.h>

void sirala(int dizi[],int boyut)
{
    int i,j;
    int gecici;
    for(i=0;i<boyut;i++){
        for(j=1;j<boyut-i;j++){
                if(dizi[j-1]>dizi[j]){
                    gecici=dizi[j-1];
                    dizi[j-1]=dizi[i];
                    dizi[i]=gecici;
                }
        }
    }
}



int main()
{
   int sayilar[5];
   int diziboyut,i;
   printf("Lutfen dizinin boyutunu giriniz.");
   scanf("&d",&diziboyut);
   printf("Lutfen siralanmasini istediginiz sayilari giriniz:");
   for(i=0;i<diziboyut;i++){
    scanf("%d",&sayilar[i]);
    }
   sirala(sayilar,diziboyut);

   for(i=0;i<diziboyut;i++)
        printf("%d",sayilar[i]);

}

/*
fonksiyon dizilerine bakicam
klasördekileri yap tekrar amaçlý anlamadýðýn yerde video izle
internetten soru çöz
*/



