#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
	FILE *file;
	file=fopen("argv[1]","r");
	
	char karakter[50];
	char istenenHece[10];
	
	int istenenHeceUzunluk,karakterUzunluk;
	
	if(file != NULL)
	{
		while(!feof(file))
		{
			fscanf(file,"%[^\n]",karakter);
			printf("%s\n",karakter);
			fscanf(file,"%s",istenenHece);
			printf("%s\n",istenenHece);	
		}
		
		istenenHeceUzunluk = strlen(istenenHece);
		karakterUzunluk = strlen(karakter);
		
		int i=0,bulundu =1;
		while(karakter[i]!='\0')
		{
			int j;
			for(j=0;j<istenenHeceUzunluk;j++)
			{
				if(karakter[i+j] != istenenHece[j] || i+istenenHeceUzunluk > karakterUzunluk)
				{
					bulundu =0;
					break;
				}
				if(j+1 == istenenHeceUzunluk)
				{
					bulundu =1;
				}		
			}
			
			if(bulundu==1)
				break;
				
			i++;
		}
		
		if(bulundu !=1)
		{
			printf("\nNot found!");
		}
		else
		{
			printf("\nBulundu:Index: %d",i+1);
		}		
	}
	else
	{
		printf("dosya bulunamadi.");
	}

	
	fclose(file);
	
	return 0;
}


