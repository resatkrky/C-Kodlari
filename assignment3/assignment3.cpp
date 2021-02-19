#include <stdio.h>
void EkranaYazdir(char str[],int uzunluk);
int For_String(char giris[],int uzunluk,int Baslangic_Index);
int Char_Bul(char giris[],int uzunluk,int Baslangic_Index,char ch);

int main( int argc,char *argv[]){
    FILE *dosya;
    FILE *Cikis_Dosya;

    char a;
    dosya=fopen("odev.txt","r");
    Cikis_Dosya = fopen("output.txt", "w");

    int i=0,Giris_Uzunlugu;

    char giris[200];
    char cikis[300];

    while((a=fgetc(dosya))!=EOF){
        giris[i]=a;
        i++;
    }
    Giris_Uzunlugu = i;

    int For_Index = For_String(giris,Giris_Uzunlugu,0);

    int birinci_parantez = Char_Bul(giris,Giris_Uzunlugu,For_Index+1,'(');
    int ikinci_parantez= Char_Bul(giris,Giris_Uzunlugu,birinci_parantez+1,')' );
    int birinci_suslu = Char_Bul(giris,Giris_Uzunlugu,For_Index+1,'{');
    int ikinci_suslu= Char_Bul(giris,Giris_Uzunlugu,birinci_suslu+1,'}' );


    int Noktalivirgul_Konumu1 = Char_Bul(giris,Giris_Uzunlugu,birinci_parantez+1,';');
    int Noktalivirgul_Konumu2 = Char_Bul(giris,Giris_Uzunlugu,Noktalivirgul_Konumu1+1,';');

    //Sayaci Tanimlamak icin kurdugum degisken.
    int Sayici_Uzunlugu = Noktalivirgul_Konumu1 - birinci_parantez - 1 ;
    char Tanim_Sayac[Sayici_Uzunlugu];

    int t = 0;
    for(int a = birinci_parantez +1;t < Sayici_Uzunlugu;t++){
        Tanim_Sayac[t] = giris[a];
        a++;
    }

    // Pars olayini elde ediyoruz.
    int Cevrim_Uzunlugu = Noktalivirgul_Konumu2 - (Noktalivirgul_Konumu1 -1) ;
    char Tanim_Dongu[Cevrim_Uzunlugu];

    t = 0;
    for(int a = Noktalivirgul_Konumu1 +1;t < Cevrim_Uzunlugu;t++){
        Tanim_Dongu[t] = giris[a];
        a++;
    }

    // For kodunda artirma kismi olan (i++) kismini elde ettigimiz bolum.
    int ForSayac_Artirma = ikinci_parantez - Noktalivirgul_Konumu2 -1 ;
    char Artirma_For[ForSayac_Artirma];

    t = 0;
    for(int a = Noktalivirgul_Konumu2 +1;t < ForSayac_Artirma;t++)
    {
        Artirma_For[t] = giris[a];
        a++;
    }

    // Dongu icini elde ettiren kod
    char Dongu_Govdesi[ikinci_suslu - birinci_suslu -1 ];
    int suslu_Dongu_Uzunlugu = 0;

    int k = 0;
    for(int j = birinci_suslu+1; j<ikinci_suslu ;j++)
    {
        Dongu_Govdesi[k] = giris[j];
        k++;
    }
    suslu_Dongu_Uzunlugu = k;

    int x = 0;
    for(int i = 0; i<Sayici_Uzunlugu;i++)
    {
        cikis[x] = Tanim_Sayac[i];
        x++;
    }

    cikis[x] = ';';
    x++;
    cikis[x] = '\n';
    x++;

    cikis[x] = 'w';
    x++;
    cikis[x] = 'h';
    x++;
    cikis[x] = 'i';
    x++;
    cikis[x] = 'l';
    x++;
    cikis[x] = 'e';
    x++;
    cikis[x] = '(';
    x++;

    for(int i = 0; i<Cevrim_Uzunlugu;i++)
    {
        cikis[x] = Tanim_Dongu[i];
        x++;
    }
    cikis[x] = ')';
    x++;

    cikis[x] = '\n';
    x++;

    cikis[x] = '{';
    x++;

    for(int i = 0; i<suslu_Dongu_Uzunlugu;i++)
    {
        cikis[x] = Dongu_Govdesi[i];
        x++;
    }

    cikis[x] = '\n';
    x++;

    for(int i = 0; i<ForSayac_Artirma;i++)
    {
        cikis[x] = Artirma_For[i];
        x++;
    }

    cikis[x] = ';';
    x++;


    cikis[x] = '\n';
    x++;

    cikis[x] = '}';
    x++;

    cikis[x] = '\n';
    x++;

    fprintf(Cikis_Dosya, cikis);

    printf("\nDosya Olusturuldu.\n");

    fclose(dosya);
    fclose(Cikis_Dosya);
    return 0;
}
int For_String(char giris[],int uzunluk,int Baslangic_Index)//For dongusunun baslangic indexini bulur.
{
    int i;
	for(i=Baslangic_Index;i<uzunluk;i++)
    {
		if(giris[i]=='f' && (giris[i+1]=='o' && uzunluk>i+1 ) && (giris[i+2]=='r' &&uzunluk>i+2) )
		return i;
	}
	return -1;
}

int Char_Bul(char giris[],int uzunluk,int Baslangic_Index,char ch)
{
	int i;
	for(i=Baslangic_Index;i<uzunluk;i++)
    {
		if(giris[i]==ch)
		return i;
	}
	return -1;
}




