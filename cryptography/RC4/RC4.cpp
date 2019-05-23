#include<stdio.h>
#include<inttypes.h>
#include<stdint.h>
#include<string.h>
#include<iostream>

#include<utility>

using namespace std;

void RC4_Encryption(char Key[] ,int key_length , char plaintext[] , int text_length , char chripttext[] )
{
	//Creation of initial state and key bytes
	unsigned char S[256] , K[256];
	for(int i = 0 ; i< 255; i++)
	{
		S[i] = i ;
		K[i] = Key[i%key_length] ;

	}
	//Permuting state bytes based on values of key bytes
	int j = 0 ;
	for(int i = 0 ; i< 255; i++)
	{
		j = (j + S[i] + K[i])%256;
		swap(S[i],S[j]);
	}
	//Continuously permuting state bytes generating keys and encrypting
	int i = 0 ;
	j = 0;
	for(int index = 0 ; index < text_length ; index++)
	{
		i = (i +1)%256;
		j = (j+S[i])%256;
		swap(S[i], S[j]);

		unsigned char k = (S[S[i]+S[j]])%256 ;
		//Key is ready encrypt
		chripttext[index] = plaintext[index] ^ k;
	}
}

int main()
{
    char arr[50] = "Hello year";
    int length = strlen(arr);
    char crypt[50] = { 0 ,};
    char re[50]= { 0 ,};
    char num = 0;
    cout << arr << endl;

    RC4_Encryption( &num ,1,arr,length,crypt );
    cout << crypt << endl;

    RC4_Encryption( &num ,1,crypt ,length,re);
    cout << re << endl;


    return 0;
}
