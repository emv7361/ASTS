#include <stdio.h>
#include <string.h> 
#include <stdint.h>
#include <stdlib.h>


int main(int argc, char** argv) {


	char letters[27] = "abcdefghijklmnopqrstuvwxyz";
	typedef char* string;
	char text[128];
	char gamma[128];
        char gamm2[128];
	char res[128];
	printf("input your text");
	scanf("%s", text);
	printf("input your key");
	scanf("%s", gamma);
	
	int sizetext = strlen(text);
	int sizegam = strlen(gamma);
	for (int i = 0; i < 128; i++)
        {
          gamm2[i]=gamma[i];
        }
        
	if (sizegam<sizetext)
	{
		while (sizegam < sizetext)
		{
			strcat(gamma, gamm2);
			sizegam = strlen(gamma);
		}
	}
	
	int *chtxt;
	int *chgam;
	
	chtxt = (int*)malloc(sizetext * sizeof(int));
	chgam = (int*)malloc(sizegam * sizeof(int));
	
	for (int i = 0; i < sizetext; i++) 
	{
		for (int j = 0; j < 27; j++)
		{
			if (text[i] == letters[j])
			{
				chtxt[i] = j;
				break;
			}

		}
	}
	for (int i = 0; i < sizegam; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (gamma[i] == letters[j])
			{
				chgam[i] = j;
				break;
			}

		}
	}
	int flag;
	printf("enter 1 if you want to encrypt or 2 if you want to decrypt");
	scanf("%d", &flag);
	
		if (flag == 1)
		{
			
			for (int i = 0; i < sizetext; i++)
			{
				int newnum = (chtxt[i] + chgam[i]) % 26;
				res[i] = letters[newnum];
			}
			printf("\n");
			printf("encrypted string");
			printf("\n");
			puts(res);
		
		}

	if (flag == 2)
	{
		for (int i = 0; i < sizetext; i++)
		{
			int newnum = (chtxt[i]+26 - chgam[i]) % 26;
			res[i] = letters[newnum];
		}
		printf("\n");
		printf("decrypted string");
		printf("\n");
		puts(res);
	}

    return 0;
}