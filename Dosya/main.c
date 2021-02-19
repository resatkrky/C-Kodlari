#include <stdio.h>
#include <stdlib.h>


int main()
{
   char yazi[30] = "Istanbul" ;
   int uzunluk = strlen(yazi);
   int i;
   FILE *fp = fopen("Deneme.txt","a");

   if(fp == NULL){
    printf("dosya olusturulamadi");
   }
   else{
        for(i=0;i < uzunluk ;i++){
            fputc(yazi[i],fp);
            printf("%c",yazi[i]);
        }printf("\nDosya Olusturuldu");

   }
   fclose(fp);
}
