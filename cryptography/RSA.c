#include  <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

#define q  3  
#define p 11
//Ű�� �ٲٰ�ʹٸ� ���⿡ ���� p,q�� �ٸ� �Ҽ��� �ٲٸ�ȴ�
/*
	This is RSA

	�۽��� bob�� n, e�� �ȴ� ����Ű
	������ alice�� n d�� �ȴ�  privet key
*/

int n = p * q;
int phin = (q - 1)*(p - 1);

int create_public_key();// return e
int gcd(int a, int d);

int extended_Euclid_for_multiple_inverse(int n, int a); 
/*
	create_personal_key return d
	ū���� �ڿ��վ���Ѵ� �ȱ׷��� ��������� �ȳ���
*/
int exponentMod(int a, int d, int N);
//encryption and decryption

int main()
{
	char array[10] = { 28,27,0,26,27,0,2,27,7 ,14 };
	int e = 7; //create_public_key(); //public key
	int private_key = extended_Euclid_for_multiple_inverse(e , phin);
	
	for (int i = 0; i < 10; i++)
	{ 
		if(exponentMod(array[i], private_key, n) == 0)
			printf(" \n");
		else
		{
			printf("%c\n", exponentMod(array[i], private_key, n) + 'a' - 1);
		}
	}
	system("pause");
	return 0;
}

int create_public_key()
{
	int e = 2;
	while (e < phin)
	{
		if (gcd(e, phin) == 1)
			break;
		else
			e++;
	}
	return e;
}


int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		gcd(b, a%b);
}

int extended_Euclid_for_multiple_inverse(int n,int a)
{
	if (gcd(a, n) != 1)
		return 0;
	int r1 = a, r2 = n;
	int t1 = 0, t2 = 1;
	int u , r, t;
	while (r2>0)
	{
		u = r1 / r2;

		r = r1%r2;
		r1 = r2; r2 = r;

		t = t1 - u * t2;
		t1 = t2; t2 = t;
	}
	if (t1 < 0)
		t1 += n;

	return t1;  //e
}

int exponentMod(int a, int d, int N)
//encryption and decryption
{
	if (a == 0)
		return 0;
	if (d == 0)
		return 1;
	long y;
	if (d % 2 == 0) {
		y = exponentMod(a, d / 2, N);
		y = (y * y) % N;
	}
	else {
		y = a % N;
		y = (y * exponentMod(a, d - 1, N) % N) % N;
	}
	return (int)((y + N) % N);
}
