#include <stdio.h>
#include <stdlib.h>

int main()
{

    char aranan[25],arayan[5];
    int uzunluk = strlen(aranan);
    int uzunluk2 = strlen(arayan);
    int i,j;

    FILE *fp = fopen("metin.txt","a");
    if(fp == NULL){
        printf("Dosya Olusturulmadi");
    }

    else{
            printf("Aranacak olan string: ");
           fgets(aranan,25,stdin);
           fputs(aranan,fp);
           fclose(fp);
    }

    FILE *fp2 = fopen("metin.txt","a");
    if(fp2 == NULL){
        printf("Dosya Olusturulmadi");
    }
    else{
            printf("\nArayacak olan string: ");
            fgets(arayan,5,stdin);
            fputs(arayan,fp2);
            fclose(fp2);
    }

    FILE *fp3 = fopen("metin.txt","r");
    if(fp3 == NULL){
        printf("Dosya Bulunamadi");
    }
    else
    {
        for(i=0;i<uzunluk;i++)
        {
            for(j=0;j<uzunluk2;j++)
            {
                if(aranan[i]==arayan[j])
                    {
                    if ( arayan[i+1]==aranan[j+1] )
                        {
                            printf("Esitlik %d.nci indiste baslar.",i);
                        }
                    }
                else
                    {
                    printf("Esitlik Bulunamadi");
                    }
            }
        }

    }




}
