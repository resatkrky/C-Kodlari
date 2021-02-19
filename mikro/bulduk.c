#include<stdio.h>
#include<string.h>

int main()
{
	FILE *file;
	file=fopen("word.txt","r");
	
	char karakter[50];
	char istenenHece[10];
	//int uzunluk=strlen()
	
	if(file != NULL)
	{
		int k=0,j=0,a=0;
		while(!feof(file))
		{
			fscanf(file,"%[^\n]",karakter);
			printf("%s\n",karakter);
			fscanf(file,"%s",istenenHece);
			printf("%s\n",istenenHece);
		}
		while(karakter[k] != '\0')
		{
			if(istenenHece[j] == karakter[k])
			{
				j++;
				a++;
				
				if(istenenHece[j] == '\0')
				{
					
					printf("%d\n",k-(a-2));
					break;	
				}
				
			}
			else if(karakter[k] == karakter[k-1])
				{
					if(istenenHece[j+1] == '\0')
					{
						printf("%d",k-(a-2));
						break;
					}	
				}
			else
			{
				j=j-a;
				a=0;
			}
			k++;
			
		}
	}
	else
	{
		printf("dosya bulunamadi.");
	}
	
	
	
	
	fclose(file);
	
	return 0;
}


