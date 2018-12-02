#pragma warning (disable: 4996)
#include<stdio.h>
#include<string.h>
void additive_cipher_Encryption(char *claertext, char *encryptext, int len, int key);
void additive_cipher_Decryption(char *claertext, char *encryptext, int len, int key);

int main()//¾ÏÈ£È­
{
	char cleartext[80] = "she is running";
	char encryptext[80];
	int n;// 0<=n<26
		  //fgets(cleartext, 80 , stdin);
	additive_cipher_Encryption(cleartext, encryptext, strlen(cleartext), 5);
	printf("%s\n", encryptext);
	printf("%s\n", cleartext);

	additive_cipher_Decryption(cleartext, encryptext, strlen(encryptext), 5);

	system("pause");
	return 0;
}

void additive_cipher_Encryption(char *claertext, char *encryptext, int len, int key)//Decryption]
{
	for (int i = 0; i <= len; i++)
	{
		if (claertext[i] >= 'a' && claertext[i] <= 'z')
		{
			encryptext[i] = claertext[i] + key - 32;
			if (encryptext[i] > 90)
				encryptext[i] -= 26;
		}
		else
			encryptext[i] = claertext[i];

	}
}// A(65)Z(90) -a(97) ±Þ°£32


void additive_cipher_Decryption(char *claertext, char *encryptext, int len, int key)//Decryption]
{
	for (int i = 0; i <= len; i++)
	{
		if (encryptext[i] >= 'A' && encryptext[i] <= 'Z')
		{
			claertext[i] = encryptext[i] - key + 32;
			if (claertext[i] < 'a')
				claertext[i] += 26;
		}
		else
			encryptext[i] = claertext[i];
	}
}// A(65)Z(90) -a(97) ±Þ°£32
