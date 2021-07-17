
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


//fibonachi
// matrix multiply return : F_n % mod
ll fibo(ll n, ll mod) 
{
	ll a[2][2] = {1,1,1,0};
	ll res[2][2] = {1,0,0,1};
	ll b[2][2];
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			b[0][0] = res[0][0];
			b[0][1] = res[0][1];
			b[1][0] = res[1][0];
			b[1][1] = res[1][1];

			res[0][0] = ((b[0][0] * a[0][0]) % mod + (b[0][1] * a[1][0]) % mod) % mod; ;
			res[0][1] = ((b[0][0] * a[0][1]) % mod + (b[0][1] * a[1][1]) % mod)%mod;
			res[1][0] = (b[1][0] * a[0][0] % mod + b[1][1] * a[1][0] % mod) % mod;
			res[1][1] = (b[1][0] * a[0][1] % mod + b[1][1] * a[1][1] % mod) % mod;
		}
		n /= 2;
		b[0][0] = (a[0][0] * a[0][0] % mod + a[0][1] * a[1][0] % mod) % mod;
		b[0][1] = (a[0][0] * a[0][1] % mod + a[0][1] * a[1][1] % mod) % mod;
		b[1][0] = (a[1][0] * a[0][0] % mod + a[1][1] * a[1][0] % mod) % mod;
		b[1][1] = (a[1][0] * a[0][1] % mod + a[1][1] * a[1][1] % mod) % mod;
			
		a[0][0] = b[0][0];
		a[0][1] = b[0][1];
		a[1][0] = b[1][0];
		a[1][1] = b[1][1];
		
	}
	return res[1][0];
}