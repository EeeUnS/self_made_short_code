#include  <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main()
{

	double sum = 0;
	int number = 0;
	FILE *fp = fopen("1209BU.txt", "r");
	//본인선택의 신청인원을 일일이 모두 추출해서 txt파일로 저장한다.
	while ((fscanf(fp, "%d", &number) != EOF))
	{
		sum += (double)number;
	}
	printf("현재 부산 울산의 공익: %d\n", (int)sum);
	sum -= 654;  //본인선택에서 뽑는 총인원수
	sum /= 382;  //선복무에서 뽑는 총인원수
	printf("선복무 갈 확률 : %lf %%\n", sum);


	system("pause");
	return 0;
}