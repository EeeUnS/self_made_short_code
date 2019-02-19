#include<stdio.h>

int main()
{
	  char  a = 10, b = 10; // a*b =c
	 char c = 0;
	 char n=0;
	printf("%d \n%d" ,a ,b );
	while(b != 0)
	{
		n = b & 1;
		b>> 1;
		a<< 1;
		if(n)
		{
			c += a;
		}
	}	
	printf("%d" ,c);
	return 0; 
}
