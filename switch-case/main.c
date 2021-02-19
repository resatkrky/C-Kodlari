#include <stdio.h>
#include <stdlib.h>


int paracekme(int tutar)
{
    int miktar=3000;
    miktar-=tutar;
    return miktar;
}


int main()
{
   int tutar;
   int bakiye=3000;
   int islem;
   int para;
   printf("ISLEMLER\n1:Para Cekme\n2:Para Yatirma\n3:Havale Yapma\n4:Bakiye Sorgulama\n5:Kart Iade\n\n\n");
   printf("Lutfen yapilacak islemi seciniz:");scanf("%d",&islem);

   switch(islem)
   {
   case 1:
       printf("Hesabinizda bulunan miktar:%d\n",bakiye);
       printf("Islem yapilacak miktar:");scanf("%d",&tutar);
       if(tutar > bakiye)
       {
           printf("Gecersiz miktar\n");
       }
       else
       {

            printf("Hesabinizdaki yeni miktar:%d",paracekme(para));
       }
        break;
   case 2:
       printf("Hesabinizda bulunan miktar:%d\n",bakiye);
       printf("Islem yapilacak miktar:");scanf("%d",&tutar);
       bakiye += tutar ;
       printf("Hesabinizdaki yeni miktar:%d",bakiye);
       break;
   case 3:
       printf("Hesabinizda bulunan miktar:%d\n",bakiye);
       printf("Havale yapilacak miktar:");scanf("%d",&tutar);
       if(tutar > bakiye)
       {
           printf("Gecersiz miktar");
       }
       else
       {
        bakiye -=tutar ;
        printf("Hesabinizdaki yeni miktar:%d",bakiye);
       }
        break;
   case 4:
       printf("Hesabinizda bulunan miktar:%d",bakiye);
       break;
   case 5:
       printf("Kart Iade Talebiniz Isleme Alinmistir.");
       break;
   default:
        printf("Lutfen 1 ile 5 arasinda sayi giriniz.");
        break;
   }
}
