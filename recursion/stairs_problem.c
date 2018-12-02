#include <stdio.h>
#include <stdlib.h>
#define MAX (100)

void walking(int pass[], int cuuren_step, int walking_length, int target);
/*현재 단계의 1단계 2단계를 진행한 각 재귀함수를 호출한다
인자값: 출력 배열,배열 인덱스,현재 총계단수,목표 총계단수*/
void printpass(int pass[], int end);
/*조건 만족하는 계단 출력*/
int main(void)
{
	int pass[MAX];
	int x;

	printf("미터를 입력하시오 : ");
	scanf("%d", &x);

	walking(pass, 0, 0, x);
	return;
}
void printpass(int pass[], int end)
{
	int i;
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
	int i;
	int current_length;

	if (walking_length == target)
	{
		printpass(pass, current_step);
		return;
	}
	else if (walking_length > target)
		return;

	for (i = 1; i <= 3; i++)
	{
		pass[current_step] = i;
		current_length = walking_length + i;//총 계단 수
		walking(pass, current_step + 1, current_length, target);
		//현재 길이가 타겟 길이보다 길시 그대로 함수 끝
	}
}
