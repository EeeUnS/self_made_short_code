#include<stdio.h>

int main()
{
	char a = 10, b = 10; // a*b =c
	char c = 0;
	char n = 0;
	printf("%d \n%d\n", a, b);
	while (b != 0)
	{
		n = b & 1;
		b = b >> 1;
		if (n)
		{
			c += a;
		}
		a = a << 1;
	}
	printf("%d", c);
	return 0;
}
