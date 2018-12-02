#include <stdio.h>
#include <stdlib.h>
#define MAX (100)
//power set
void npr(int pass[], int r, int n, int current_r);
/*npr�� ��� ����� ���� ����Ѵ�.
���ڰ�: ��� �迭,r,n,����r*/
void printpass(int pass[], int end);
/*���� �����ϴ� ���� ���*/
int samesearch(int pass[], int i, int current_r);
/*�ߺ��� �˻��ϴ� �Լ� ���� �ε��� �迭�� ���ؼ� �ߺ��Ǵ� ���� �����Ѵ� */
int main(void)
{
	int pass[MAX] = { 0, };
	int x;

	printf("������ ������ �Է��ϼ��� : ");
	scanf("%d", &x);

	for (int i = 00; i <= x; i++)
	{
		npr(pass, i, x, 0);
	}

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
		//�ߺ����˻�


		i = samesearch(pass, i, current_r);
		if (i>n)
			return;
		npr(pass, r, n, current_r + 1);
	}
}
int samesearch(int pass[], int i, int current_r)
{
	for (int j = 0; j<current_r; j++)
	{
		if (pass[j] == pass[current_r])
		{
			pass[current_r] = ++i;
			i = samesearch(pass, i, current_r);
		}
	}
	return i;
}
