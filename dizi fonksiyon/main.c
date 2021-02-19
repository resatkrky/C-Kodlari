#include <stdio.h>
#include <stdlib.h>

/*
int bastir(int matris[],int matrisinuzunlugu)
{
    int i,carpim=1;
    for(i=0; i < matrisinuzunlugu ;i++)
    {
        carpim=carpim*matris[i];
    }
    return carpim;
}
*/

void yazdir(int matris[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",matris[i][j]);
        }
        printf("\n");
    }

}




int main()
{
   /*
    int dizi[9]={1,2,3,4,5,};
    printf("%d",bastir(dizi,5));
    */

    int dizi[4][4];
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&dizi[i][j]);
        }
    }
    yazdir(dizi);

}
