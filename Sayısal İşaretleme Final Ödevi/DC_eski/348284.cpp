#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14f
#define WAV_HEADER_LENGTH 44
#define L2B_ENDIAN(n) (((n) >> 24)&0xff) | (((n) << 8) & 0xff0000) | (((n) >> 8) & 0xff00) | (((n) << 24) & 0xff000000)
#define N 16
#define uzunluk 20

//348284 - RESAT KARAKAYA 1.OGRETÝM

char* WavOku(const char* adiDosya, short* c_ch, short* s_ornek, int* c_ornek)
{
	FILE* fp = fopen(adiDosya, "rb"); // Dosyayi Ac

	if (!fp)
	{
		fprintf(stderr, "Dosya Acilamadi \"%s\"\n", adiDosya);
		exit(0);
	}
    fprintf(stderr, "Dosya Acildi \"%s\"\n", adiDosya);
	fseek(fp, 0, SEEK_END);
	int dosya_boyutu = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	printf("Dosya \"%s\" %d byte\n\n", adiDosya, dosya_boyutu); //dosya byte sayisi

	char* buffer = (char*)malloc(sizeof(char) * dosya_boyutu);
	fread(buffer, dosya_boyutu, 1, fp);

	*c_ch = *(short*)&buffer[22];
	*s_ornek = *(short*)&buffer[34] / 8;
	*c_ornek = *(int*)&buffer[40] / *s_ornek;

	printf("YiginBoyutu :\t %u\n", *(int*)&buffer[4]); //yiginin boyutu
	printf("Format :\t %u\n", *(short*)&buffer[20]); //format
	printf("SayiKanallari :\t %u\n", *(short*)&buffer[22]); //sayi kanallari
	printf("OrnekOrani :\t %u\n", *(int*)&buffer[24]);	// saniyedeki ornek sayisi
	printf("ByteOrani :\t %u\n", *(int*)&buffer[28]);		// saniyedeki byte sayisi
	printf("OrnekBasinaBit :\t %u\n", *(short*)&buffer[34]); //her ornek icin bit sayisi
	printf("IDaltParcasi :\t \"%c%c%c%c\"\n", buffer[36], buffer[37], buffer[38], buffer[39]);	// veri bolumunun baslangici
	printf("BoyutAltParcasi :\t %u\n", *(int*)&buffer[40]);		// veri boyutu
	printf("Sure :\t %fs\n\n", (float)(*(int*)&buffer[40]) / *(int*)&buffer[28]); //gecen sure

	fclose(fp);
	return buffer;
}

void WavYaz(const char* adiDosya, const char* veri, int boyut) {
	FILE* fp = fopen(adiDosya, "wb");

	if (!fp)
	{
		fprintf(stderr, "Dosya Olusturulamadi \"%s\"\n", adiDosya);
		exit(0);
	}
    fprintf(stderr, "Dosya Olusturuldu \"%s\"\n", adiDosya);
	fwrite(veri, boyut, 1, fp);
	fclose(fp);
}

//i_frek ve r_rfrek .csv uzantili dosyaya yaz
void CsvYaz(const char* adiDosya, const float* i_frek, const float* r_frek, int c_frek)
{
	FILE* fp = fopen(adiDosya, "w");

	if (!fp)
	{
		fprintf(stderr, "Dosya Olusturulamadi \"%s\"\n", adiDosya);
		exit(0);
	}
    fprintf(stderr, "Dosya Olusturuldu \"%s\"\n", adiDosya);
	fprintf(fp, "i_frek,r_frek\n");
	for (int i = 0; i < c_frek; i++)
	{
		fprintf(fp, "%.4f,%.4f\n", i_frek[i], r_frek[i]);
	}
	fclose(fp);
}

int main()
{
	short n_ch, s_ornek;
	int c_ornek, secim = 0;
	printf("Verilen FIR Filtre degerleriyle islem yapmak icin 1'e basin\n");
	printf("Kendiniz FIR Filtre degerleri girerek islem yapmak icin 2'ye basin\n\n");
	printf("Lutfen Yapacaginiz Islemi Secin:");
	scanf("%d",&secim);

	char* buffer = WavOku("girdi.wav", &n_ch, &s_ornek, &c_ornek);
    short* veri = (short*)&buffer[WAV_HEADER_LENGTH];

    int c_frek = N / 2;
    float* r_frek = (float*)malloc(sizeof(double) * c_frek); //frekans reel kismi
    float* i_frek = (float*)malloc(sizeof(double) * c_frek); //frekans sanal kismi

    //DFT islemi baslangic
    int k = 0;
    while(k < c_frek)
	{
        r_frek[k] = i_frek[k] = 0.0f;
        int i = 0;
        while(i < N)
		{
            r_frek[k] += veri[i * c_ornek / N] * cos(2 * PI * k * i / N);
            i_frek[k] -= veri[i * c_ornek / N] * sin(2 * PI * k * i / N);
            i++;
        }
        k++;
    }
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
    int t=0;
    while(t < c_frek)
    {
        i_frek[t]=(i_frek[t]-i_min)/(i_max-i_min);
        r_frek[t]=(r_frek[t]-r_min)/(r_max-r_min);
        t++;
    }
    //DFT islemi bitis

	if(secim == 1)
    {
        //fir filtre coef
        const int fir_uzunluk = 7;
        const float FIR[7] = {0.4f, 0.8f, 1.2f, 0.5f, 0.7f, 0.2f, 0.4f};

        //low and high pass
        const int lowhigh_uzunluk = 12;
        float low_pass[12] = {0.022, -0.083, -0.083, 0.083, 0.311, 0.417, 0.311, 0.083, -0.083, -0.083, 0.022, 0.083};
        float high_pass[12] = {-0.022, -0.083, 0.083, -0.083, 0.311, -0.417, 0.311, -0.083, 0.083, -0.083, -0.022, 0.083};

        // cikis sinyali tanimlama

        const int cikis_uzunluk1 = c_ornek - fir_uzunluk + 1;
        const int cikis_uzunluk2 = c_ornek - lowhigh_uzunluk + 1;
        float* cikis1 = (float*)malloc(sizeof(float) * cikis_uzunluk1);
        float* cikis2 = (float*)malloc(sizeof(float) * cikis_uzunluk2);
        float* cikis3 = (float*)malloc(sizeof(float) * cikis_uzunluk2);

        // Giris Sinyalinden ve Fir Filtreden Cikis Sinyal Uretimi

        for (int i = 0; i < cikis_uzunluk1; i++)
		 {
            cikis1[i] = 0.0f;
            for (int j = 0; j < fir_uzunluk; j++)
			{
				cikis1[i] += veri[i + j] * FIR[j];
			}

        }
        for (int i = 0; i < cikis_uzunluk2; i++)
		{
            cikis2[i] = 0.0f;
            for (int j = 0; j < lowhigh_uzunluk; j++)
			{
				cikis2[i] += veri[i + j] * low_pass[j];
			}

        }
        for (int i = 0; i < cikis_uzunluk2; i++)
		{
            cikis3[i] = 0.0f;
            for (int j = 0; j < lowhigh_uzunluk; j++)
			{
				cikis3[i] += veri[i + j] * high_pass[j];
			}

        }

        // yazdirma islemi
        printf("FIR Filter\n");
        for (int i = 0; i < 10; i++)
		{
			printf("%.2f\n", cikis1[i]);
		}

        printf("\nLow Pass\n");
        for (int i = 0; i < 10; i++)
		{
			printf("%.2f\n", cikis2[i]);
		}

        printf("\nHigh Pass\n");
        for (int i = 0; i < 10; i++)
		{
			printf("%.2f\n", cikis3[i]);
		}
        printf("\n");

        WavYaz("cikti.wav", buffer, c_ornek * s_ornek + WAV_HEADER_LENGTH);
        CsvYaz("cikti.csv", i_frek, r_frek, c_frek);
	}
	else if(secim == 2)
    {
        //fir filtre coef
        int firUzunluk = 0;
        float Fir[uzunluk];
        printf("Lutfen FIR Filtrenin Kac Deger Olacagini Giriniz: ");
        scanf("%d",&firUzunluk);

        printf("Lutfen FIR Filtrenin Degerlerini Giriniz: ");
        for(t=0; t<firUzunluk ; t++)
		{
            scanf("%f",&Fir[t]);
        }

        // cikis sinyali tanimlama
        const int cikisUzunluk = c_ornek - firUzunluk + 1;
        float* cikis = (float*)malloc(sizeof(float) * cikisUzunluk);

        // Giris Sinyalinden ve Fir Filtreden Cikis Sinyal Uretimi

        for (int i = 0; i < cikisUzunluk; i++)
		{
            cikis[i] = 0.0f;
            for (int j = 0; j < firUzunluk; j++)
			{
				cikis[i] += veri[i + j] * Fir[j];
			}
        }

        // yazdirma islemi
        printf("\nFIR Filter\n");
        for (int i = 0; i < 10; i++)
		{
			printf("%.2f\n", cikis[i]);
		}
        printf("\n");

        WavYaz("cikti.wav", buffer, c_ornek * s_ornek + WAV_HEADER_LENGTH);
        CsvYaz("cikti.csv", i_frek, r_frek, c_frek);
	}
	else
    {
        printf("Yanlis deger girdiniz.");
	}
}
