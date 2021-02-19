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


/* int *p bir pointer olarak tanýmlanýr
p=&sayi
& sayinin bellekteki adresini verir bu yuzden p pointeri da sayinin adresteki yerini verir
buradaki p deðerini yazdýrýrken printf("%p",p); kullanýlýr bu printf("%p",&sayi); ile ayni seydir
*p deðerini yazdýrmak istersek * isareti pointerin bellekteki adresinde bulunan degeri verir
bunu yazdýrmak icin de %d kullanýlýr printf("%d",*p);*/
