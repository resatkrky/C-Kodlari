#include <stdio.h>
#include <stdlib.h>

int main()
{

/*
   int i;
   for(i=0;i<10;i++)
   {

       if(i==5)
       {
           break;
       }
        printf("%d\n",i);
   }
*/

    int i,sayi,toplam=0;
    for(i=0;i<2;i++)
    {
        printf("Lutfen sayi giriniz :"); scanf("%d",&sayi);
        if(sayi==4)
        {
            break;
        }
        toplam+=sayi;
    }
    printf("%d",toplam);


/*
    int i;
    for(i=0;i<10;i++)
    {
        if(i%2==0)
        {
            continue;
        }
        printf("%d\n",i);
    }
*/


}
