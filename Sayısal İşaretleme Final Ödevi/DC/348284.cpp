#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14f
#define WAV_HEADER_LENGTH 44
#define L2B_ENDIAN(n) (((n) >> 24)&0xff) | (((n) << 8) & 0xff0000) | (((n) >> 8) & 0xff00) | (((n) << 24) & 0xff000000)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//348284 - RESAT KARAKAYA 1.OGRETÝM

//wav dosyasindan okuma yapar
char* WavOku(const char* adiDosya, short* n_ch, short* s_ornek, int* c_ornek)
{
	FILE* fp = fopen(adiDosya, "rb"); // Dosyayi Ac

	if (!fp)
    {
		fprintf(stderr, "Dosya Acilamadi \"%s\"\n", adiDosya);
		exit(0);
	}
    fprintf(stderr, "Dosya Acildi \"%s\"\n\n", adiDosya);
	fseek(fp, 0, SEEK_END);
	int dosya_boyutu = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	printf("Dosya \"%s\" %d byte\n\n", adiDosya, dosya_boyutu); //dosya byte sayisi

	char* buffer = (char*)malloc(sizeof(char) * dosya_boyutu);
	fread(buffer, dosya_boyutu, 1, fp);

	*n_ch = *(short*)&buffer[22]; //wavin mono mu yoksa stereo mu oldugunu belirtir
	*s_ornek = *(short*)&buffer[34] / 8; //wavdaki bir örnegin byte cinsinden boyutu
	*c_ornek = *(int*)&buffer[40] / *s_ornek; //wavdaki ornek sayisi

	printf("YiginBoyutu :\t %u\n", *(int*)&buffer[4]); //yiginin boyutu
	printf("Format :\t %u\n", *(short*)&buffer[20]);
	printf("SayiKanallari :\t %u\n", *(short*)&buffer[22]); //sayi kanallari
	printf("OrnekOrani :\t %u\n", *(int*)&buffer[24]);	//saniyedeki ornek sayisi
	printf("ByteOrani :\t %u\n", *(int*)&buffer[28]);  //saniyedeki byte sayisi
	printf("OrnekBasinaBit :\t %u\n", *(short*)&buffer[34]);  //her ornek icin bit sayisi
	printf("IDaltParcasi :\t \"%c%c%c%c\"\n", buffer[36], buffer[37], buffer[38], buffer[39]);	// veri bolumunun baslangici
	printf("BoyutAltParcasi :\t %u\n", *(int*)&buffer[40]);		// veri boyutu
	printf("Sure :\t %fs\n\n", (float)(*(int*)&buffer[40]) / *(int*)&buffer[28]); //gecen sure

	fclose(fp);
	return buffer;
}
//wav dosyasi yazar
void WavYaz(const char* adiDosya, const char* veri, int boyut)
{
	FILE* fp = fopen(adiDosya, "wb");

	if (!fp)
    {
		fprintf(stderr, "Dosya Olusturulamadi \"%s\"\n", adiDosya);
		exit(0);
	}
    fprintf(stderr, "Dosya Olusturuldu \"%s\"\n\n", adiDosya);
	fwrite(veri, boyut, 1, fp);
	fclose(fp);
}

//iki wav dosyasini toplayip bir wav dosyasý olusturur
void WavTopla(const char* dosya1, const char* dosya2, const char* dosya3)
 {
	int c_ornek;
	short n_ch, s_ornek;

	const char* buffer1 = WavOku(dosya1, &n_ch, &s_ornek, &c_ornek);
	short* girdi1 = (short*)&buffer1[WAV_HEADER_LENGTH];

	const char* buffer2 = WavOku(dosya2, &n_ch, &s_ornek, &c_ornek);
	const short* girdi2 = (short*)&buffer2[WAV_HEADER_LENGTH];

	for (int i = 0; i < c_ornek; i++)
    {
        girdi1[i] += (girdi2[i] / 5);
    }
	WavYaz(dosya3, buffer1, c_ornek * s_ornek + WAV_HEADER_LENGTH);
}

//wav dosyasinin sinyal verilerini tutar
void SinyalYaz(const char* adiDosya, const short* girdi, const short* cikti, int c_ornek)
{
	FILE* fp = fopen(adiDosya, "w");

	if (!fp)
    {
		fprintf(stderr, "Dosya Olusturulamadi \"%s\"\n", adiDosya);
		exit(0);
	}
    fprintf(stderr, "Dosya Olusturuldu \"%s\"\n\n", adiDosya);
	fprintf(fp, "girdi,cikti\n");
	for (int i = 0; i < c_ornek; i++)
    {
        fprintf(fp, "%d,%d\n", girdi[i], cikti[i]);
	}
	fclose(fp);
}

int main()
{
    int i, j, k, c_ornek,secim;
    short n_ch, s_ornek;
	float toplam;
	const int firUzunluk = 12;
	int fir_uzunluk=0;

	printf("High Pass ile Islem Yapmak icin 1'e basiniz.\n");
    printf("Low Pass ile Islem Yapmak icin 2'ye basiniz.\n");
    printf("Kendiniz FIR Filtre Katsayilari Girerek Islem Yapmak icin 3'ye basiniz.\n");
    printf("Lutfen Yapacaginiz Islemi Secin: ");
    scanf("%d",&secim);
    printf("\n");

	//WavTopla("t1.wav", "t2.wav", "tToplam.wav");

    const char* buffer = WavOku("girdi.wav", &n_ch, &s_ornek, &c_ornek);
    short* girdi = (short*)&buffer[WAV_HEADER_LENGTH];
	short* cikti = (short*)malloc(sizeof(short) * c_ornek);

    if(secim == 1)
    {
        const float high_pass[] = { -0.022f, - 0.083f, 0.083f, - 0.083f, - 0.083f, 0.311f, - 0.417f, 0.311f, - 0.083f, 0.083f, - 0.083f, - 0.022f, 0.083 };

        for (i = 0; i < c_ornek; i++)
        {
            toplam = 0.0f;
            for (j = 0; j < firUzunluk; j++)
            {
                k = i - j;
                if (k >= 0)
                    toplam += high_pass[j] * girdi[k];
            }
            cikti[i] = toplam;
        }

        for (i = 0; i < c_ornek; i++)
        {
            girdi[i] = cikti[i];
        }

        WavYaz("high.wav", buffer, c_ornek * s_ornek + WAV_HEADER_LENGTH);
        SinyalYaz("high.csv", girdi, cikti, c_ornek);
        WavTopla("t1.wav", "t2.wav", "tToplam.wav");
    }
    else if(secim == 2)
    {
        const float low_pass[] = { 0.022f, -0.083f,-0.083f, 0.083f, 0.311f, 0.417f, 0.311f, 0.083f, -0.083f, -0.083f, 0.022f, 0.083f };

        for (i = 0; i < c_ornek; i++)
        {
            toplam = 0.0f;
            for (j = 0; j < firUzunluk; j++)
            {
                k = i - j;
                if (k >= 0)
                    toplam += low_pass[j] * girdi[k];
            }
            cikti[i] = toplam;
        }

        for (i = 0; i < c_ornek; i++)
        {
            girdi[i] = cikti[i];
        }

        WavYaz("low.wav", buffer, c_ornek * s_ornek + WAV_HEADER_LENGTH);
        SinyalYaz("low.csv", girdi, cikti, c_ornek);
        WavTopla("t1.wav", "t2.wav", "tToplam.wav");
    }
    else if(secim == 3)
    {
        while(fir_uzunluk<=0)
        {
            printf("Girilecek FIR katsayisi adedini giriniz : ");
            scanf("%d",&fir_uzunluk);
        }

        float* FIR = new float[fir_uzunluk];
        printf("Kullanilacak FIR Filtre katsayilarini giriniz : ");
        for(int t=0;t<fir_uzunluk;t++)
        {
            scanf("%f",&FIR[t]);
        }
        printf("\n");

        for (i = 0; i < c_ornek; i++)
        {
            toplam = 0.0f;
            for (j = 0; j < fir_uzunluk; j++)
            {
                k = i - j;
                if (k >= 0)
                    toplam += FIR[j] * girdi[k];
            }
            cikti[i] = toplam;
        }

        for (i = 0; i < c_ornek; i++)
        {
            girdi[i] = cikti[i];
        }

        WavYaz("FIR.wav", buffer, c_ornek * s_ornek + WAV_HEADER_LENGTH);
        SinyalYaz("FIR.csv", girdi, cikti, c_ornek);
        WavTopla("t1.wav", "t2.wav", "tToplam.wav");
    }
    else
    {
        printf("Yanlis Tusa Bastiniz.");
    }
}
