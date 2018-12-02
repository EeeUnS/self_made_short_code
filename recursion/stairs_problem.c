#include <stdio.h>
#include <stdlib.h>
#define MAX (100)

void walking(int pass[], int cuuren_step, int walking_length, int target);
/*���� �ܰ��� 1�ܰ� 2�ܰ踦 ������ �� ����Լ��� ȣ���Ѵ�
���ڰ�: ��� �迭,�迭 �ε���,���� �Ѱ�ܼ�,��ǥ �Ѱ�ܼ�*/
void printpass(int pass[], int end);
/*���� �����ϴ� ��� ���*/
int main(void)
{
	int pass[MAX];
	int x;

	printf("���͸� �Է��Ͻÿ� : ");
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
		current_length = walking_length + i;//�� ��� ��
		walking(pass, current_step + 1, current_length, target);
		//���� ���̰� Ÿ�� ���̺��� ��� �״�� �Լ� ��
	}
}
