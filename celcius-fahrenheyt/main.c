#include <stdio.h>
#include <stdlib.h>

int cel_to_fahr(int celsius)
{
    //celcius=f-32*10/18
    int f;
    f=(celsius*1.8)+32;
    return f;
}



int main()
{
   int celcius;
   printf("Lutfen donusturulecek aciyi giriniz:");scanf("%d",&celcius);
   if(celcius>=0 && celcius<=180)
    {
    printf("%d celcius=%d fahrenheyt",celcius,cel_to_fahr(celcius));
   }
    else{
        printf("Lutfen 0 ile 180 arasinda sayi giriniz.");
    }
}
