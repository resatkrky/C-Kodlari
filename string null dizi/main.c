#include <stdio.h>
#include <stdlib.h>

int uzunluk (char ad[])
{
    int uzunluk=0;
    int i;
    for(i=0; ad[i] !='\0' ;i++)
    {
        uzunluk++;
    }return uzunluk;
}


int main()
{
    char isim[]="Resat";
    printf("%d",uzunluk(isim));// strlen(isim) fonk u da ayni islemi yapar
}
