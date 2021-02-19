#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dizi[3][3];
    int i,j;
    printf("Lutfen matrisin degerlerini alt alta giriniz:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&dizi[i][j]);
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",dizi[i][j]);
        }
        printf("\n");
    }

    int toplam=0;
    printf("Her sutunun toplam degeri sirasiyla\n");
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            toplam +=dizi[i][j];
        }
        printf("%d\n",toplam);
        toplam=0;
        }

    int toplam2=0;
    printf("Her satirin toplam degeri sirasiyla\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            toplam2=toplam2+dizi[i][j];
        }
        printf("%d ",toplam2);
        toplam2=0;
    }


}
