#pragma warning (disable: 4996)
#include<stdio.h>
#include<string.h>
void additive_cipher_Decryption(char *claertext, char *encryptext, int len, int key);

int main()//��ȣȭ
{
	char cleartext[80] = { 0, };
	char encryptext[80] = { 0, };
	puts("��ȣ���� �Է��ϼ���");
	fgets(encryptext, 80, stdin);

	for (int i = 0; i < 26; i++)
	{
		additive_cipher_Decryption(cleartext, encryptext, strlen(encryptext), i);
		printf("key %d �϶� �� %s", i, cleartext);
	}

	system("pause");
	return 0;
}


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
			claertext[i] = encryptext[i];
	}
}// A(65)Z(90) -a(97) �ް�32