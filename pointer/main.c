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


/* int *p bir pointer olarak tanımlanır
p=&sayi
& sayinin bellekteki adresini verir bu yuzden p pointeri da sayinin adresteki yerini verir
buradaki p değerini yazdırırken printf("%p",p); kullanılır bu printf("%p",&sayi); ile ayni seydir
*p değerini yazdırmak istersek * isareti pointerin bellekteki adresinde bulunan degeri verir
bunu yazdırmak icin de %d kullanılır printf("%d",*p);*/
