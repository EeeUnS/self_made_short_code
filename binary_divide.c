#include<cstdio>

const int bit = 16;

int main()
{
    int a = 101;
    int b = 3;
    int divisor = b, remainder = a, quotient = 0;
    divisor = divisor << bit;

    for(int i = 0 ; i < bit+1 ; i ++)
    {
        remainder -= divisor; //a
        if(remainder < 0 ) // 2b
        {
            remainder += divisor;
            quotient  = quotient << 1;
        }
        else //2a
        {
            quotient  = quotient << 1;
            quotient += 1;
        }
        divisor = divisor>>1;
    }
    printf("%d를  %d로 나눈 결과 몫 %d 나머지 %d", a,b,quotient, remainder);
    return 0;
}
