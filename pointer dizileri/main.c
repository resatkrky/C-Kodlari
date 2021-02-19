#include <stdio.h>
#include <stdlib.h>

char *hangiay(char *diziadi[],int uzunluk,int hangiay)
{


    if(hangiay <7 && hangiay >0)
    {
        return diziadi[hangiay-1];
    }

    else{
        printf("Bos");

    }


}


int main()
{
    char *aylar[6] = {"Ocak","Subat","Mart","Nisan","Mayis","Haziran"};

    char *p = hangiay(aylar,6,3);
    printf("%s",p);
}
