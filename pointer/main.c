#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi=18,*p;

    p = &sayi;

    printf("%p\n",&sayi);

     printf("%d\n",&sayi);

    printf("%p\n",p);

    printf("%d\n",p);

    printf("%p\n",*p);

    printf("%d",*p);
}


/* int *p bir pointer olarak tan�mlan�r
p=&sayi
& sayinin bellekteki adresini verir bu yuzden p pointeri da sayinin adresteki yerini verir
buradaki p de�erini yazd�r�rken printf("%p",p); kullan�l�r bu printf("%p",&sayi); ile ayni seydir
*p de�erini yazd�rmak istersek * isareti pointerin bellekteki adresinde bulunan degeri verir
bunu yazd�rmak icin de %d kullan�l�r printf("%d",*p);*/
