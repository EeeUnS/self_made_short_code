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


void setting()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}


int dx[] = { -1,0,0,1 , 0 , 0 };
int dy[] = { 0,-1,1,0 , 0 , 0 };



#ifdef _XUTILITY_
	freopen("input.txt", "r", stdin);
#endif // DEBUG