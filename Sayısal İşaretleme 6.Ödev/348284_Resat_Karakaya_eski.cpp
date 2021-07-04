#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14f
#define baslikUzunluguWav 44
#define l2b_endian(n) (((n) >> 24)&0xff) | (((n) << 8) & 0xff0000) | (((n) >> 8) & 0xff00) | (((n) << 24) & 0xff000000)

//348284 - Reşat KARAKAYA - 1.Ogretim
using namespace std;

char* WavOku(const char* adiDosya, short* n_ch, short* s_ornek, int* c_ornek)
{

	FILE* dosya = fopen(adiDosya, "rb"); // Dosyayi Ac

	if (!dosya) {
		fprintf(stderr, "Dosya acilamadi \"%s\"\n", adiDosya);
		exit(0);
	}

	fseek(dosya, 0, SEEK_END);
	int dosya_boyutu = ftell(dosya);
	fseek(dosya, 0, SEEK_SET);

	printf("Dosya \"%s\" has %d byte\n\n", adiDosya, dosya_boyutu); //dosya byte sayisi

	char* buf = (char*)malloc(sizeof(char) * dosya_boyutu); //buffer
	fread(buf, dosya_boyutu, 1, dosya);

	*n_ch = *(short*)&buf[22];
	*s_ornek = *(short*)&buf[34] / 8;
	*c_ornek = *(int*)&buf[40] / *s_ornek;

	printf("OrnekOrani :\t %u\n", *(int*)&buf[24]);	// saniyedeki ornek sayisi
	printf("BitOrani :\t %u\n", *(int*)&buf[28]);		// saniyedeki byte sayisi
	printf("OrnekBasinaBit : %u\n", *(short*)&buf[34]); //her ornek icin bit sayisi
	printf("IDaltParcasi :\t \"%c%c%c%c\"\n", buf[36], buf[37], buf[38], buf[39]);	// veri bölumunun baslangici
	printf("BoyutAltParcasi : %u\n", *(int*)&buf[40]);		// veri boyutu
	printf("Sure :\t\t %fs\n", (float)(*(int*)&buf[40]) / *(int*)&buf[28]); //sure
	printf("YiginBoyutu :\t %u\n", *(int*)&buf[4]); //yiginin boyutu
	printf("Format :\t %u\n", *(short*)&buf[20]);
	printf("SayiKanallari :\t %u\n", *(short*)&buf[22]);

	fclose(dosya);
	return buf;
}

void WavYaz(const char* adiDosya, const char* veri, int boyut)
{
	FILE* dosya = fopen(adiDosya, "wb");

	if (!dosya) {
		fprintf(stderr, "Dosya Olusturulamadi \"%s\"\n", adiDosya);
		exit(0);
	}
    fprintf(stderr, "Dosya Olusturuldu \"%s\"\n", adiDosya);
	fwrite(veri, boyut, 1, dosya);
	fclose(dosya);
}

int main()
{
    int c_ornek;
    short n_ch, s_ornek;
    char* buf = WavOku("girdi.wav", &n_ch, &s_ornek, &c_ornek); //wav dosyasi
    short* data = (short*)&buf[baslikUzunluguWav];
    int N = 200;
    int c_frek = N / 2;
    double* r_frek = (double*)malloc(sizeof(double) * c_frek); //frekans reel kismi
    double* i_frek = (double*)malloc(sizeof(double) * c_frek); //frekans sanal kismi
    ofstream dosya;
    dosya.open("frekans.txt");
    printf("\nDFT isleme basladi...\n");
    int k = 0;
    while(k < c_frek){
        r_frek[k] = i_frek[k] = 0.0f;
        int i = 0;
        while(i < N){
            r_frek[k] += data[i * c_ornek / N] * cos(2 * pi * k * i / N);
            i_frek[k] -= data[i * c_ornek / N] * sin(2 * pi * k * i / N);
            i++;
        }
        k++;
    }
    printf("bitti\n\n");
    double i_min=i_frek[0],i_max=i_frek[0],r_min=r_frek[0],r_max=r_frek[0];
    int z=0;
    while(z < c_frek)
    {
        if(i_min>i_frek[z]) i_min=i_frek[z];
        if(i_max<i_frek[z]) i_max=i_frek[z];
        if(r_min>r_frek[z]) r_min=r_frek[z];
        if(r_max<r_frek[z]) r_max=r_frek[z];
        z++;
    }
    for(int y=0;y<c_frek;y++)
    {

    }
    int t=0;
    while(t < c_frek)
    {
        i_frek[t]=(i_frek[t]-i_min)/(i_max-i_min);
        r_frek[t]=(r_frek[t]-r_min)/(r_max-r_min);
        t++;
    }
    dosya<<"r_frek:"<<"                     "<<"i_frek:\n";
    printf("r_frek \t\t i_frek\n\n");
    for(int i = 0; i < c_frek; i++){
        printf("%.8f \t %.8f", r_frek[i], i_frek[i]);
    printf("\n");
    dosya<<r_frek[i]<<"                     "<<i_frek[i]<<"\n";
}
    dosya.close();
    printf("\n");

    WavYaz("cikti.wav", buf, c_ornek * s_ornek + baslikUzunluguWav);
}



