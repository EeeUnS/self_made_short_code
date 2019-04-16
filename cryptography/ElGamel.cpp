#include<stdio.h>
#include<inttypes.h>
#include<iostream>
///ElGamel

#include<utility>

int p; //private key
int e_1;
int d;
int e_2;


int gcd(int a, int b);
int extended_Euclid_for_multiple_inverse(int n,int a);//n의 a에대한 역수를 반환합니다..
void ElGamal_Key_Generation();
int exponentMod(int a, int d, int N);
std::pair<int,int> ElGamal_Enryption(int e_1,int e_2,int p,int P);
int ElGamal_Decryption(int d, int p , int C_1,int C_2);

void ElGamal_Key_Generation()
{
	p = 11 ;
	e_1 = 2;
	d = 8;
	e_2 = exponentMod(e_1, d ,p);
}

std::pair<int,int>  ElGamal_Enryption(int e_1,int e_2,int p,int P)
{
	int r =4 ;
	int C_1 = exponentMod(e_1,r,p);
	int C = exponentMod(e_2,r,p);

    int C_2 = (C*P)%p;
	return std::pair<int, int>(C_1,C_2);

}

int ElGamal_Decryption(int d, int p , int C_1,int C_2)
{
	int inversC_1 = exponentMod(C_1,d,p);
    int T = extended_Euclid_for_multiple_inverse(inversC_1,p);

	int P = (C_2*T) %p;
	return P ;
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
int exponentMod(int a, int d, int N) // a^d mod N
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
int main()
{
    ElGamal_Key_Generation();
    std::pair<int,int> di = ElGamal_Enryption( e_1, e_2, p, 9);
    std::cout << di.first <<" " << di.second<<std::endl;

    int a = ElGamal_Decryption( d,  p , di.first , di.second);
    std::cout << a << std::endl;

    return 0;
}
