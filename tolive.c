#include  <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main()
{

	double sum = 0;
	int number = 0;
	FILE *fp = fopen("1209BU.txt" , "r");  
	//���μ����� ��û�ο��� ������ ��� �����ؼ� txt���Ϸ� �����Ѵ�.
	while ((fscanf(fp, "%d", &number) != EOF))
	{
		sum += (double)number;
	}
	sum -= 654;  //���μ��ÿ��� �̴� ���ο���
	sum /= 382;  //���������� �̴� ���ο���
	printf("����� : %lf %%\n" , sum);

	
	system("pause");
	return 0;
}