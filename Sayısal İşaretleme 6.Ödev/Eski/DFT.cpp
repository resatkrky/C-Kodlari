#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14f
#define wav_baslik_uzunlugu 44
#define l2b_endian(n) (((n) >> 24)&0xff) | (((n) << 8) & 0xff0000) | (((n) >> 8) & 0xff00) | (((n) << 24) & 0xff000000)

char* wav_oku(const char* adiDosya, short* n_ch, short* s_ornek, int* c_ornek)
{
	FILE* fp = fopen(adiDosya, "rb"); // Dosyayý Ac

	if (!fp) {
		fprintf(stderr, "Dosya acilamadi \"%s\"\n", adiDosya);
		exit(0);
	}

	fseek(fp, 0, SEEK_END);
	int boyut_dosya = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	printf("Dosya \"%s\" %d bit\n\n", adiDosya, boyut_dosya);

	char* buf = (char*)malloc(sizeof(char) * boyut_dosya);
	fread(buf, boyut_dosya, 1, fp);

	// DUMP THE buffer INFO

	*n_ch = *(short*)&buf[22];
	*s_ornek = *(short*)&buf[34] / 8;
	*c_ornek = *(int*)&buf[40] / *s_ornek;

	printf("ChunkSize :\t %u\n", *(int*)&buf[4]);
	printf("Format :\t %u\n", *(short*)&buf[20]);
	printf("NumChannels :\t %u\n", *(short*)&buf[22]);
	printf("SampleRate :\t %u\n", *(int*)&buf[24]);	// number of samples per second
	printf("ByteRate :\t %u\n", *(int*)&buf[28]);		// number of bytes per second
	printf("BitsPerSample :\t %u\n", *(short*)&buf[34]);
	printf("Subchunk2ID :\t \"%c%c%c%c\"\n", buf[36], buf[37], buf[38], buf[39]);	// marks beginning of the data section
	printf("Subchunk2Size :\t %u\n", *(int*)&buf[40]);		// size of data (byte)
	printf("Duration :\t %fs\n\n", (float)(*(int*)&buf[40]) / *(int*)&buf[28]);

	fclose(fp);
	return buf;
}

void wav_yaz(const char* adiDosya, const char* veri, int uzunluk) {
	FILE* fp = fopen(adiDosya, "wb");

	if (!fp) {
		fprintf(stderr, "Dosya acilamadi \"%s\"\n", adiDosya);
		exit(0);
	}

	fwrite(veri, uzunluk, 1, fp);
	fclose(fp);
}

int main()
{
    short n_ch, s_ornek;
    int c_ornek;

    char* buf = wav_oku("preamble10.wav", &n_ch, &s_ornek, &c_ornek);
    short* veri = (short*)&buf[wav_baslik_uzunlugu];

    int N = 1000;
    int cfrek = N / 2;
    float* rfrek = (float*)malloc(sizeof(float) * cfrek);
    float* ifrek = (float*)malloc(sizeof(float) * cfrek);

    printf("DFT isleme basladi...\n");
    int k=0;
    while(k < cfrek){
        rfrek[k] = ifrek[k] = 0.0f;
        int i=0;
        while(i < N){
            rfrek[k] += veri[i * c_ornek / N] * cos(2 * pi * k * i / N);
            ifrek[k] -= veri[i * c_ornek / N] * sin(2 * pi * k * i / N);
            i++;
        }
        k++;
    }
    printf("bitti\n\n");

    printf("ifrek \t\t rfrek\n\n");
    for(int i = 0; i < 10; i++)
        printf("%.2f \t %.2f\n", rfrek[i], ifrek[i]);
    printf("\n...\n");

    wav_yaz("test.wav", buf, c_ornek * s_ornek + wav_baslik_uzunlugu);
}
