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




vi KMP(const char* T,const char* P)
{
  	vi vec;
    vi PI;
	int psize = strlen(P);
	PI.resize(psize);
	
	PI[0] = -1;
	int k = -1;
	for (int q = 1 ;  q< psize ; q++)
	{
		while (k > 0 && P[k + 1] != P[q])
		{
			k = PI[k];
		}
		if (P[k + 1] == P[q])
		{
			k++;
		}
		PI[q] = k;
	}

	int q = -1;
	int n = strlen(T);
	for(int  i= 0 ;i <  n;i++)
	{
		while (q >= 0 && P[q + 1] != T[i])
		{
			q = PI[q];
		}
		if (P[q + 1] == T[i])
		{
			q++;
		}
		if (q == psize-1)
		{
			//matcing
			//ASSERT(false);
			vec.push_back(i - psize + 1 ) ;
			q = PI[q];
		}
	}
}

/*
vec.size : 겹치는 갯수
vec 원소 : 겹치는 인덱스
T (0...n-1)
*/