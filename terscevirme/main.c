#include <stdio.h>
#include <stdlib.h>

void terscevir(char ad[])
{
    char gecici;
    int uzunluk,i;
    uzunluk=strlen(ad);
    for(i=0;i<uzunluk/2;i++)
    {
        gecici=ad[i];
        ad[i]=ad[uzunluk-1-i];
        ad[uzunluk-1-i]=gecici;
    }
    printf("%s",ad);

}


int main()
{
   char isim[50];
   scanf("%s",&isim);
   terscevir(isim);
}

