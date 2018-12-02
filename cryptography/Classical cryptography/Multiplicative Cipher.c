#pragma warning (disable: 4996)
#include<stdio.h>
#include<string.h>
void multiplicative_cipher_Decryption(char *claertext, char *encryptext, int len, int key);
void multiplicative_cipher_Encryption(char *claertext, char *encryptext, int len, int key);
int gcd_returninverse(int a, int b);

int main()//암호화
{
	char cleartext[80] = "hello";
	char encryptext[80];
	puts("암호문을 입력하세요");
	//fgets(encryptext, 80 , stdin);
	multiplicative_cipher_Encryption(cleartext, encryptext, strlen(cleartext), 7);
	multiplicative_cipher_Decryption(cleartext, encryptext, strlen(cleartext), 7);
	printf("%s\n", encryptext);
	printf("%s\n", cleartext);

	system("pause");
	return 0;
}


void multiplicative_cipher_Encryption(char *claertext, char *encryptext, int len, int key)//Decryption]
{
	int inverse_key = gcd_returninverse(26, key);
	if (inverse_key == 0)
	{
		printf("key가 26과 서로소가 아니라서 역원이 존재하지않습니다\n");
		return;
	}
	for (int i = 0; i <= len; i++)
	{

		if (claertext[i] >= 'a' && claertext[i] <= 'z')
		{
			encryptext[i] = ((claertext[i] - 'a')*key) % 26 + 'A';
		}
		else
			encryptext[i] = claertext[i];

	}
}// A(65)Z(90) -a(97) 급간32



void multiplicative_cipher_Decryption(char *claertext, char *encryptext, int len, int key)//Decryption]
{
	int inverse_key = gcd_returninverse(26, key);
	if (inverse_key == 0)
	{
		printf("key가 26과 서로소가 아니라서 역원이 존재하지않습니다\n");
		return;
	}
	while (inverse_key < 0)
	{
		inverse_key += 26;
	}
	for (int i = 0; i <= len; i++)
	{
		if (encryptext[i] >= 'A' && encryptext[i] <= 'Z')
		{
			claertext[i] = ((encryptext[i] - 'A')*inverse_key) % 26 + 'a';
		}
		else
			claertext[i] = encryptext[i];
	}
}// A(65)Z(90) -a(97) 급간32

int gcd_returninverse(int a, int b)
{
	int r;

	int q, t1 = 0, t2 = 1, t;
	while (b)
	{
		r = a % b;
		q = a / b;
		a = b;
		b = r;
		t = t1 - t2 * q;
		t1 = t2;
		t2 = t;
	}
	if (a != 1)
		return 0;
	return t1;
}
