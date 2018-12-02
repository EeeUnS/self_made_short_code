#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#pragma warning(disable:4996)

#define MAX (100)
//power set
void npr(int pass[], int r, int n, int current_r);
/*npr의 모든 경우의 수를 출력한다.
인자값: 출력 배열,r,n,현재r*/
void printpass(int pass[], int end);
/*조건 만족하는 순열 출력*/
int samesearch(int pass[], int i, int current_r);
/*중복도 검사하는 함수 앞의 인덱스 배열과 비교해서 중복되는 값을 제거한다 */
int main(void)
{
	int pass[MAX] = { 0, };
	int x;

	printf("집합의 갯수를 입력하세요 : ");
	scanf("%d", &x);

	for (int i = 00; i <= x; i++)
	{
		npr(pass, i, x, 0);
	}
	system("pause");
	return 0;
}
void printpass(int pass[], int end)
{
	printf("{");
	for (int i = 0; i <= end; i++)
	{
		printf(" %d", pass[i]);
	}
	printf(" }\n");
}
void npr(int pass[], int r, int n, int current_r)
{
	if (r == current_r)
	{
		printpass(pass, r - 1);
		return;
	}
	for (int i = 1; ; i++)
	{
		pass[current_r] = i;
		//중복도검사


		i = samesearch(pass, i, current_r);
		if (i > n)
			return;
		npr(pass, r, n, current_r + 1);
	}
}
int samesearch(int pass[], int i, int current_r)
{
	for (int j = 0; j < current_r; j++)
	{
		if (pass[j] >= pass[current_r])
		{
			pass[current_r] = ++i;
			i = samesearch(pass, i, current_r);
		}
	}
	return i;
}
