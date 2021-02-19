#include <stdio.h>
#include <stdlib.h>

void no_of_digits(int value){

            if(value >= 1 && value <= 99){
                if(value >= 1 && value <= 9) {
                printf("Sayi 1 basamaklidir.\n");
                }
                if(value >= 10 && value <= 99) {
                printf("Sayi 2 basamaklidir.\n");
                }
                }

                else
                    printf("Sayi verilen aralikta degil 1 ile 99 arasinda giriniz.\n");


}

int main()
{
   int number,uzunluk,i;
   printf("Lutfen kac adet sayi girilecegini belirtiniz:");
   scanf("%d",&uzunluk);

   for(i=0;i<uzunluk;i++){
    printf("1 ile 99 arasinda bir sayi giriniz : ");
      scanf("%d", &number);
      no_of_digits(number);

   }


}

