#include <stdio.h>
#include <stdlib.h>

struct bilgi {
    int yas;
    int dogumtarih;
};

struct aile{
    char baba[10];
    char anne[10];
    char abi[10];
    char abla[10];
    struct bilgi karakaya;

};

void fonk(struct aile karakaya){
    strcpy(karakaya.baba,"Ibrahim");
    strcpy(karakaya.anne,"Fatma");
    strcpy(karakaya.abi,"Mehmet");
    strcpy(karakaya.abla,"Gamze");
    karakaya.karakaya.yas=50;
    karakaya.karakaya.dogumtarih=1965;
    printf("%s %d %d %s %s %s",karakaya.baba,karakaya.karakaya.yas,karakaya.karakaya.dogumtarih,karakaya.anne,karakaya.abi,karakaya.abla);

}

int main()
{
    struct aile karakaya12;
    fonk(karakaya12);


    return 0;
}
