#pragma warning (disable: 4996)
#include<stdio.h>
#include<string.h>
void autokey_cipher_Decryption(char *cleartext, char *encryptext, int len, int first_key);

int main()//암호화
{
	char cleartext[80] = { 0, };
	char encryptext[80] = "MTMTCM SA LHRDY";
	puts("암호문을 입력하세요");
	//fgets(encryptext, 80 , stdin);
	for (int i = 0; i < 26; i++)
	{
		autokey_cipher_Decryption(cleartext, encryptext, strlen(encryptext), i);
		printf("key %d 일때 평문 %s\n", i, cleartext);
	}

	system("pause");
	return 0;
}

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
