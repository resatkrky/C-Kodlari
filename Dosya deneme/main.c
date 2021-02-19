#include <stdio.h>
#include <stdlib.h>

int main()
{
   char metin[250];
   FILE *fp = fopen("yazdir.txt","w");
   int i;
   if (fp == NULL){
        printf("Dosya Olusturulamadi");
   }
   else{
    printf("Lutfen yazma islemini yapiniz.\n");

        fgets(metin,250,stdin);
    }
    for(i=0;i < strlen(metin) ;i++){
        fputc(metin[i],fp);
    }
    printf("Dosya Olusturuldu.");
    fclose(fp);

}
