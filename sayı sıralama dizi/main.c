#include <stdio.h>
#include <stdlib.h>

int main()
{
   int dizi[80],adet,gecici,i,j;
   printf("Kac adet sayi girilecek:");
   scanf("%d",&adet);

  for(i=0;i<adet;i++)
  {
      printf("%d.sayiyi giriniz:",i+1);
      scanf("%d",&dizi[i]);
  }

  for(i=0;i<adet-1;i++){
        for(j=i+1;j<adet;j++){
                if(dizi[i]>dizi[j])
            {
                gecici=dizi[i];
                dizi[i]=dizi[j];
                dizi[j]=gecici;
            }
        }


        }

    for(i;i<adet;i++)
        printf("%d",dizi[i]);




}
