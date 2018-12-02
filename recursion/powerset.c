#include <stdio.h>
#include <stdlib.h>
#define MAX (100)
//power set
void walking(int pass[], int cuuren_step, int walking_length, int target);
/*���� �ܰ��� 1�ܰ� 2�ܰ踦 ������ �� ����Լ��� ȣ���Ѵ�
���ڰ�: ��� �迭,�迭 �ε���,���� n,n*/
void printpass(int pass[], int end);
/*���� �����ϴ� ��� ���*/
int main(void)
{
	int pass[MAX] = { 0, };
	int x;

	printf("������ ������ �Է��ϼ��� : ");
	scanf("%d", &x);

	walking(pass, 0, 1, x);
	return;
}
void printpass(int pass[], int end)
{
	int i;
	if (end == -1)
	{
		printf("������\n");
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
	//���� �ε����� ���� n�� ������ �ȳ����� �ΰ��� �ִ´�.
	if (walking_length == target)//n�� �������� ����Ѵ�.
	{
		printpass(pass, current_step - 1);//�ε��� current_step���� ���� ������ �ʴ�.
		pass[current_step] = walking_length;
		printpass(pass, current_step);
		return;
	}
	walking(pass, current_step, walking_length + 1, target);
	pass[current_step] = walking_length;
	walking(pass, current_step + 1, walking_length + 1, target);
}
