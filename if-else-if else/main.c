#include <stdio.h>
#include <stdlib.h>

int main()
{
   int vize,final;
   float ort;
   printf("Lutfen vize notu giriniz:"); scanf("%d",&vize);
   printf("Lutfen final notu giriniz:"); scanf("%d",&final);

   ort=vize*0.4+final*0.6;

   if(ort>=90 && ort<=100)
   {
       printf("Not ortalamaniz %f ve Harf notunuz AA",ort);
   }
   else if(ort<=90 && ort>=70)
   {
       printf("Not ortalamaniz %f ve Harf notunuz BB",ort);
   }
   else if(ort<=70 && ort>=60)
   {
       printf("Not ortalamaniz %f ve Harf notunuz CC",ort);
   }
   else if(ort<=60 && ort>=45)
   {
       printf("Not ortalamaniz %f ve Harf notunuz DD",ort);
   }
   else if(ort<=45 && ort>=0)
   {
       printf("Not ortalamaniz %f ve Harf notunuz FF",ort);
   }
   else
   {
       printf("Lütfen 100 ve 0 arasinda sayi giriniz.");
   }
}
