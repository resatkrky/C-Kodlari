#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayilar[3],i;
    for(i=0;i<3;i++)
    {
        printf("%d'inci sayiyi giriniz:",i+1);
        scanf("%d",&sayilar[i]);
    }

    if(sayilar[0]<sayilar[1] && sayilar[0]<sayilar[2])
    {
        if(sayilar[1]<sayilar[2])
        {
            printf("%d %d %d",sayilar[0],sayilar[1],sayilar[2]);
        }
        else
             printf("%d %d %d",sayilar[0],sayilar[2],sayilar[1]);
    }

    if(sayilar[1]<sayilar[0] && sayilar[1]<sayilar[2])
    {
        if(sayilar[0]<sayilar[2])
        {
            printf("%d %d %d",sayilar[1],sayilar[0],sayilar[2]);
        }
        else
            printf("%d %d %d",sayilar[1],sayilar[2],sayilar[0]);
        }

    if(sayilar[2]<sayilar[0] && sayilar[2]<sayilar[1])
    {
        if(sayilar[0]<sayilar[2])
        {
            printf("%d %d %d",sayilar[2],sayilar[0],sayilar[1]);
        }
        else
            printf("%d %d %d",sayilar[2],sayilar[1],sayilar[0]);
        }




}
