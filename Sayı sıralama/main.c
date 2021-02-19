#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi1,sayi2,sayi3;
    printf("Lutfen 1.sayiyi giriniz:");scanf("%d",&sayi1);
    printf("Lutfen 2.sayiyi giriniz:");scanf("%d",&sayi2);
    printf("Lutfen 3.sayiyi giriniz:");scanf("%d",&sayi3);


    //sayi1 en küçük
    if(sayi1<sayi2 && sayi1<sayi3)
    {
        if(sayi2<sayi3)
        {
            printf("%d %d %d",sayi1,sayi2,sayi3);
        }
        else
             printf("%d %d %d",sayi1,sayi3,sayi2);
    }

    //sayi 2 en küçük
    if(sayi2<sayi1 && sayi2<sayi3)
    {
        if(sayi1<sayi3)
        {
            printf("%d %d %d",sayi2,sayi1,sayi3);
        }
        else
             printf("%d %d %d",sayi2,sayi3,sayi1);
    }

    //sayi 3 en küçük
    if(sayi3<sayi2 && sayi3<sayi1)
    {
        if(sayi1<sayi2)
        {
            printf("%d %d %d",sayi3,sayi1,sayi2);
        }
        else
             printf("%d %d %d",sayi3,sayi2,sayi2);
    }
}
