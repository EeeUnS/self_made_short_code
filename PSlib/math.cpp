#include <iostream>
#include<unordered_map>
#include<algorithm>
#include <vector>
#include<list>
#include<queue>
#include <set>
#include<map>
#include<stack>
#include<cmath>
#include<string.h>
#include <complex>
#include <vector>
#include <algorithm>
#include<cstdio>
#ifdef _XUTILITY_
#define ASSERT(expr, ...) if(!(expr)) __asm{ int 3 }
#else
#define ASSERT(expr, ...) 
#endif // DEBUG


using namespace std;
#define ffor(i,x)  for(int i = 0 ; i < x ; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> matrix;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;




ll gcd(ll a,ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}



ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b ;
}



ll extended_Euclid_for_multiple_inverse( ll a, ll mod_n)
{
	if (gcd(a, mod_n) != 1)
		return -1;
	 ll r1 = a, r2 = mod_n;
	ll t1 = 0, t2 = 1;
	 ll u, r, t;
	while (r2 > 0)
	{
		u = r1 / r2;

		r = r1 % r2;
		r1 = r2; r2 = r;

		t = t1 - u * t2;
		t1 = t2; t2 = t;
	}
	if (t1 < 0)
		t1 += mod_n;

	return t1;  //e
}



ll exponent_Mod( ll base,  ll exponent,  ll mod_N)
//encryption and decryption
{
	if (base == 0)
		return 0;
	if (exponent == 0)
		return 1;
	ll y;

	if (exponent % 2 == 0) {
		y = exponent_Mod(base, exponent / 2, mod_N);
		y = (y * y) % mod_N;
	}
	else {
		y = base % mod_N;
		y = (y * exponent_Mod(base, exponent - 1, mod_N) % mod_N) % mod_N;
	}
	return ((y + mod_N) % mod_N);
}

ll factorialMod(ll n, ll mod)
{
	if (n == 0)
	{
		return 1;
	}
	ll tmp = 1;
	for (int i = 2; i <= n; i++)
	{
		tmp *= i;
		tmp %=mod;
	}
	return tmp;
}





inline matrix matrix_multiply(const matrix& a, const matrix& b)
{
	const int colSize = a.size();
	const int multnum = a[0].size();
	const int rowSize = b[0].size();
	matrix base(colSize, vector<ll>(rowSize));

	ffor(i, rowSize)
	{
		ffor(j, colSize)
		{
			ffor(k, multnum)
			{
				base[i][j] += a[i][j] * b[i][j];
			}
		}
	}
	return base;
}

inline matrix matrixMultiplyMod(const matrix& a, const matrix& b, const ll mod)
{
	const int colSize = a.size();
	const int multnum = a[0].size();
	const int rowSize = b[0].size();
	matrix base(colSize, vector<ll>(rowSize));

	ffor(i, rowSize)
	{
		ffor(j, colSize)
		{
			ffor(k, multnum)
			{
				base[i][j] += (a[i][k] * b[k][j]);
			}
			base[i][j] %= mod;
		}
	}
	return base;
}


matrix matrixPowMod(matrix& a, ll n, ll modulo)
{
	const int size = a.size();
	matrix res(size, vector<ll>(size));
	ffor(i, size)
	{
		res[i][i] = 1;
	}
	while (n > 0) 
	{
		if (n % 2 == 1)
		{
			res = matrixMultiplyMod(res, a, modulo);
		}
		n /= 2;
		a = matrixMultiplyMod(a, a, modulo);
	}
	return res;
}

constexpr int combsize= 102;
ll combination[combsize][combsize];

//nCm
ll nCm(ll n, ll m)
{
	combination[1][0] = 1;
	combination[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		combination[i][0] = 1;
		for (int j = 1; j <= m; j++) {
			combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
		}
	}
	return combination[n][m];
}



struct bigint {
	long long one;
	long long two;
	bigint operator+(bigint &a)
	{
		bigint tmp;
		tmp.two = two + a.two;
		tmp.one = one + a.one + tmp.two / 1'000'000'000'000'000'000;
		tmp.two %= 1'000'000'000'000'000'000;
		return tmp;
	}
};