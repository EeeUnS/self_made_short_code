#include<stdio.h>
#include<string.h>

char A[10003] = { 0,};
char B[10003] = { 0,};
char C[10003] = { 0,};
#include<string.h>
int main()
{
    scanf("%s", A);
    scanf("%s", B);
    int A_len = strlen(A);
    int B_len = strlen(B);
    int length  = (A_len > B_len  ?  A_len : B_len);
    int short_length = (A_len < B_len  ?  A_len : B_len);
    int i= 0;
    char last_carry;
    int carry = 0;
    for( ; i < short_length ; i++)
    {
        int a = A[A_len-i-1]-'0' + B[B_len-i-1]-'0'+carry;
        if( a >= 10)
        {
            carry = 1;
            a %= 10;
        }
        else
        {
            carry = 0;
        }
        C[length-1-i] =a + '0';
    }
    for( ; i < length ; i++)
    {
        if(carry == 1)
        {
            if(length == A_len)
            {
                int a = A[length-1-i] +carry-'0';
                if( a >= 10)
                {
                    carry = 1;
                    a %= 10;
                }
                else
                {
                    carry = 0;
                }
                C[length-1-i]=a+'0';
            }
            else
            {
                int a=B[length-1-i]+carry-'0';
                if( a >= 10)
                {
                    carry = 1;
                    a %= 10;
                }
                else
                {
                    carry = 0;
                }
                C[length-1-i]=a+'0';

            }
        }
        else
        {
            if(length == A_len)
            {
                C[length-1-i]=A[length-1-i];
            }
            else
            {
                C[length-1-i]=B[length-1-i];
            }
        }
    }
    if(carry == 1)
    {
        printf("1%s",C);

    }
    else
    {
        printf("%s",C);

    }



}
