#include<stdio.h>
#include<string.h>
#include<ctype.h>
void rail_fence_Decryption(char *cleartext, char *encryptext, int len );
void rail_fence_Encryption(char *cleartext, char *encryptext, int len );


int main()//암호화
{
    char cleartext[80] =  "meet me at the park" ; //"attack is today";
    char encryptext[80] = { 0, };
    puts("암호문을 입력하세요");
    //fgets(cleartext, 80 , stdin);
    rail_fence_Encryption(cleartext, encryptext, strlen(cleartext));
    printf("%s\n", encryptext);

    rail_fence_Decryption(cleartext, encryptext, strlen(cleartext));

    printf("%s\n", cleartext);

    return 0;
}

void rail_fence_Encryption(char *cleartext, char *encryptext, int len) //Decryption]
{
    int en_index= 0;
    for(int  j = 0 ; j < 2; j++)
    {
        for(int i = j ; i < len ; i += 2)
        {
            if(!isspace(cleartext[i]))
            {
                encryptext[en_index++] = cleartext[i] + 'A' -'a';
            }
            else
            {
                encryptext[en_index++] = 'X';
            }
        }
    }

}// A(65)Z(90) -a(97) 급간32

void rail_fence_Decryption(char *cleartext, char *encryptext, int len)//Decryption]
{
    int cl_index= 0;
    int length = 0;
    if(len % 2 == 1)
    {
            length =  len/2 +1;
    }
    else
    {
        length =  len/2 ;
    }

    for(int  j = 0 ; j < length; j++)
    {
        cleartext[cl_index++] = encryptext[j] - 'A' + 'a';
        if(!(len % 2 == 1 && j == length -1))
            cleartext[cl_index++] = encryptext[j+length] - 'A' + 'a';
    }
}// A(65)Z(90) -a(97) 급간32
