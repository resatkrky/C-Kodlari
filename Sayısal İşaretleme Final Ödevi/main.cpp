#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* read_wav(const char* filename, short*, short*, int*);

//Tanýmlamalar
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14f
#define WAV_HEADER_LENGTH 44
#define L2B_ENDIAN(n) (((n) >> 24)&0xff) | (((n) << 8) & 0xff0000) | (((n) >> 8) & 0xff00) | (((n) << 24) & 0xff000000)

void write_wav(const char* filename, const char*, int);

int main()
{
    //sum_wav("1khz.wav", "10khz.wav", "sum.wav");

    int fir_length=0;
    while(fir_length<=0)
    {
        printf("FIR katsayi adedini giriniz : ");
        scanf("%d",&fir_length);
    }

    float* low_fir = new float[fir_length];
    printf("Kullanilacak katsayilari giriniz : ");
    for(int counter=0;counter<fir_length;counter++)
        scanf("%f",&low_fir[counter]);

    int i, j, k, csample;
    short nchannel, ssample;
    float toplam;

    const char* buffer = read_wav("sum.wav", &nchannel, &ssample, &csample);
    short* input = (short*)&buffer[WAV_HEADER_LENGTH];
    short* output = (short*)malloc(sizeof(short) * csample);

    for (i = 0; i < csample; i++)
    {
        toplam = 0.0f;
        for (j = 0; j < fir_length; j++)
        {
            k = i - j;
            if (k >= 0)
                toplam += low_fir[j] * input[k];
        }
        output[i] = toplam;
    }

    for (i = 0; i < csample; i++)
        input[i] = output[i];
    write_wav("low.wav", buffer, csample * ssample + WAV_HEADER_LENGTH);
    //write_csv("high.csv", inp, out, csample);
}


char* read_wav(const char* filename, short* nchannel, short* ssample, int* csample)
{
    FILE* fp = fopen(filename, "rb");

    if (!fp)
    {
        fprintf(stderr, "Couldn't open the file \"%s\"\n", filename);
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    printf("The file \"%s\" has %d bytes\n\n", filename, file_size);

    char* buffer = (char*)malloc(sizeof(char) * file_size);
    fread(buffer, file_size, 1, fp);

    // DUMP THE buffer INFO

    *nchannel = *(short*)&buffer[22];
    *ssample = *(short*)&buffer[34] / 8;
    *csample = *(int*)&buffer[40] / *ssample;

    printf("ChunkSize :\t %u\n", *(int*)&buffer[4]);
    printf("Format :\t %u\n", *(short*)&buffer[20]);
    printf("NumChannels :\t %u\n", *(short*)&buffer[22]);
    printf("SampleRate :\t %u\n", *(int*)&buffer[24]);	// number of samples per second
    printf("ByteRate :\t %u\n", *(int*)&buffer[28]);		// number of bytes per second
    printf("BitsPerSample :\t %u\n", *(short*)&buffer[34]);
    printf("Subchunk2ID :\t \"%c%c%c%c\"\n", buffer[36], buffer[37], buffer[38], buffer[39]);	// marks beginning of the data section
    printf("Subchunk2Size :\t %u\n", *(int*)&buffer[40]);		// size of data (byte)
    printf("Duration :\t %fs\n\n", (float)(*(int*)&buffer[40]) / *(int*)&buffer[28]);

    fclose(fp);
    return buffer;
}

void write_wav(const char* filename, const char* data, int len)
{
    FILE* fp = fopen(filename, "wb");

    if (!fp)
    {
        fprintf(stderr, "Couldn't open the file \"%s\"\n", filename);
        exit(0);
    }

    fwrite(data, len, 1, fp);
    fclose(fp);
}

