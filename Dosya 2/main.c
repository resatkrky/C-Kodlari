#include <stdio.h>
#include <stdlib.h>

int main()
{
    char yazi[500];
    FILE *fp = fopen("deneme.txt","w");

    if(fp == NULL){
        printf("Dosya olusturulamadi");
    }
    else{
        printf("Lutfen yazma islemini yapiniz: ");
        fgets(yazi,500,stdin);
        fputs(yazi,fp);
        printf("Dosya Olusturuldu");
        fclose(fp);
    }
}
