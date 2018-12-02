#pragma warning (disable: 4996)
#include<stdio.h>
#include<string.h>
void multiplicative_cipher_Decryption(char *claertext, char *encryptext, int len, int key);
int gcd_returninverse(int a, int b);

int main()//��ȣȭ
{
	char cleartext[80];
	char encryptext[80];
	puts("��ȣ���� �Է��ϼ���");
	fgets(encryptext, 80, stdin);

	for (int i = 1; i < 26; i++)//0~26���� ���ʿ䰡���� ���μҰ��ƴϸ� ����������
	{
		multiplicative_cipher_Decryption(cleartext, encryptext, strlen(encryptext), i);
		printf("key %d �϶� �� %s", i, cleartext);
	}

	system("pause");
	return 0;
}

void multiplicative_cipher_Decryption(char *claertext, char *encryptext, int len, int key)//Decryption]
{
	int inverse_key = gcd_returninverse(26, key);
	if (inverse_key == 0)
	{
		printf("key�� 26�� ���μҰ� �ƴ϶� ������ ���������ʽ��ϴ�\n");
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
}// A(65)Z(90) -a(97) �ް�32

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
