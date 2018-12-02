#pragma warning (disable: 4996)
#include<stdio.h>
#include<string.h>
void affine_cipher_Decryption(char *cleartext, char *encryptext, int len, int multiplicative_key, int additive_key);
void affine_cipher_Encryption(char *cleartext, char *encryptext, int len, int multiplicative_key, int additive_key);
int gcd_returninverse(int a, int b);

int main()//암호화
{
	char cleartext[80] = "hello";
	char encryptext[80];
	puts("암호문을 입력하세요");
	//fgets(cleartext, 80 , stdin);
	affine_cipher_Encryption(cleartext, encryptext, strlen(cleartext), 7, 2);
	affine_cipher_Decryption(cleartext, encryptext, strlen(cleartext), 7, 2);
	printf("%s\n", encryptext);
	printf("%s\n", cleartext);

	system("pause");
	return 0;
}

void affine_cipher_Encryption(char *cleartext, char *encryptext, int len, int multiplicative_key, int additive_key)//Decryption]
{
	int inverse_key = gcd_returninverse(26, multiplicative_key);
	if (inverse_key == 0)
	{
		printf("key가 26과 서로소가 아니라서 역원이 존재하지않습니다\n");
		return;
	}
	for (int i = 0; i <= len; i++)
	{

		if (cleartext[i] >= 'a' && cleartext[i] <= 'z')
		{
			encryptext[i] = ((cleartext[i] - 'a')*multiplicative_key + additive_key) % 26 + 'A';
		}
		else
			encryptext[i] = cleartext[i];

	}
}// A(65)Z(90) -a(97) 급간32

void affine_cipher_Decryption(char *cleartext, char *encryptext, int len, int multiplicative_key, int additive_key)//Decryption]
{
	int inverse_key = gcd_returninverse(26, multiplicative_key);
	if (inverse_key == 0)
	{
		printf("key가 26과 서로소가 아니라서 역원이 존재하지않습니다");
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
			cleartext[i] = (inverse_key * (encryptext[i] - 'A' + 26 - additive_key)) % 26 + 'a';
		}
		else
			cleartext[i] = encryptext[i];
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