#pragma warning (disable: 4996)
#include<stdio.h>
#include<string.h>
void autokey_cipher_Decryption(char *cleartext, char *encryptext, int len, int first_key);
void autokey_cipher_Encryption(char *cleartext, char *encryptext, int len, int first_key);

int main()//암호화
{
	char cleartext[80] = "attack is today";
	char encryptext[80] = { 0, };
	puts("암호문을 입력하세요");
	//fgets(cleartext, 80 , stdin);
	autokey_cipher_Encryption(cleartext, encryptext, strlen(cleartext), 12);
	autokey_cipher_Decryption(cleartext, encryptext, strlen(encryptext), 12);
	printf("%s\n", encryptext);
	printf("%s\n", cleartext);

	system("pause");
	return 0;
}

void autokey_cipher_Encryption(char *cleartext, char *encryptext, int len, int first_key)//Decryption]
{
	char key = first_key;

	for (int i = 0; i < len; i++)
	{
		if (cleartext[i] >= 'a' && cleartext[i] <= 'z')
		{
			encryptext[i] = cleartext[i] + key - 32;
			if (encryptext[i] > 90)
				encryptext[i] -= 26;
			key = cleartext[i] - 'a';
		}
		else
			encryptext[i] = cleartext[i];

	}

}// A(65)Z(90) -a(97) 급간32

void autokey_cipher_Decryption(char *cleartext, char *encryptext, int len, int first_key)//Decryption]
{
	int key = first_key;
	for (int i = 0; i < len; i++)
	{
		if (encryptext[i] >= 'A' && encryptext[i] <= 'Z')
		{
			cleartext[i] = encryptext[i] - key + 32;
			if (cleartext[i] < 'a')
				cleartext[i] += 26;
			key = encryptext[i] - 'A' - key;
			if (key < 0)
				key += 26;
		}
		else
			cleartext[i] = encryptext[i];
	}
}// A(65)Z(90) -a(97) 급간32
