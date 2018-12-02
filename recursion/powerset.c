#include <stdio.h>
#include <stdlib.h>
#define MAX (100)
//power set
void walking(int pass[], int cuuren_step, int walking_length, int target);
/*현재 단계의 1단계 2단계를 진행한 각 재귀함수를 호출한다
인자값: 출력 배열,배열 인덱스,현재 n,n*/
void printpass(int pass[], int end);
/*조건 만족하는 계단 출력*/
int main(void)
{
	int pass[MAX] = { 0, };
	int x;

	printf("집합의 갯수를 입력하세요 : ");
	scanf("%d", &x);

	walking(pass, 0, 1, x);
	return;
}
void printpass(int pass[], int end)
{
	int i;
	if (end == -1)
	{
		printf("공집합\n");
		return;
	}
	for (i = 0; i <= end; i++)
	{
		if (i != 0)
		{
			printf("-");
		}
		printf("%d", pass[i]);
	}
	printf("\n");
}
void walking(int pass[], int current_step, int walking_length, int target)
{
	//현재 인덱스에 현재 n을 넣은것 안넣은것 두개를 넣는다.
	if (walking_length == target)//n이 같아질때 출력한다.
	{
		printpass(pass, current_step - 1);//인덱스 current_step에는 값이 들어가있지 않다.
		pass[current_step] = walking_length;
		printpass(pass, current_step);
		return;
	}
	walking(pass, current_step, walking_length + 1, target);
	pass[current_step] = walking_length;
	walking(pass, current_step + 1, walking_length + 1, target);
}
