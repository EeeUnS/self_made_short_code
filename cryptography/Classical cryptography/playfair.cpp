#include<stdio.h>
//#include<string.h>


const char key[5][5]={
{'l','g','d','b','a'},
{'q','m','h','e','c'},
{'u','r','n','i','f'}, //I = J
{'x','v','s','o','k'},
{'z','y','w','t','p'}
};
char fake_key = 'x';



void playfair_Decryption(char *cleartext, char *encryptext, int len );
void playfair_Encryption(char *cleartext, char *encryptext, int len);


int main()//암호화
{
	char cleartext[80] =  "hello" ; //"attack is today";
	char encryptext[80] = { 0, };
	puts("암호문을 입력하세요");
	//fgets(cleartext, 80 , stdin);
	playfair_Encryption(cleartext, encryptext, strlen(cleartext));
	printf("%s\n", encryptext);

	playfair_Decryption(cleartext, encryptext, strlen(cleartext));

	printf("%s\n", cleartext);

	return 0;
}

void playfair_Encryption(char *cleartext, char *encryptext, int len )//Decryption]
{
    int en_index = 0;
    for(int cl_index = 0 ; cl_index < len ; )
    {
        char faira = cleartext[cl_index];
        char fairb = 0;
        if(cl_index == len-1 || faira == cleartext[cl_index+1])
        {
            fairb = fake_key;
            cl_index++;
        }
        else
        {
            fairb = cleartext[cl_index+1];
            cl_index += 2;
        }
        int i = 0,j = 0 ,k = 0,r = 0 ;

        for(i = 0 ; i < 5 ; i++)
        {
            for(j = 0 ; j < 5 ; j++)
            {
                if(faira == key[i][j] || (faira == 'j' && 'i' == key[i][j]))
                {
                    //탈출문
                    goto returna;
                }
            }
        }
returna:
         for(k = 0 ; k < 5 ; k++)
        {
            for(r = 0 ; r < 5 ; r++)
            {
                if(fairb == key[k][r] || (fairb == 'j' && 'i' == key[k][r]))
                {
                    //탈출문
                    goto returnb;
                }
            }
        }
returnb:

    if(i == k)
    {
        encryptext[en_index++] = key[i][(j+1)%5]+'A'-'a';
        encryptext[en_index++] = key[k][(r+1)%5]+'A'-'a';

    }else if( j == r)
    {
         encryptext[en_index++] = key[(i+1)%5][j]+'A'-'a';
        encryptext[en_index++] = key[(k+1)%5][r] +'A'-'a' ;
    }
    else
    {
         encryptext[en_index++] = key[i][r]+'A'-'a';
        encryptext[en_index++] = key[k][j]+'A'-'a';
    }
    }
}// A(65)Z(90) -a(97) 급간32

void playfair_Decryption(char *cleartext, char *encryptext, int len )//Decryption]
{
    int cl_index = 0;
    for(int en_index = 0 ; en_index < len ; )
    {
        char faira = encryptext[en_index] - 'A' +'a';
        char fairb = 0;
        if(en_index == len-1 || faira == encryptext[en_index+1])
        {
            fairb = fake_key;
            en_index++;
        }
        else
        {
            fairb = encryptext[en_index+1] - 'A' +'a';
            en_index += 2;
        }
        int i = 0,j = 0 ,k = 0,r = 0 ;

        for(i = 0 ; i < 5 ; i++)
        {
            for(j = 0 ; j < 5 ; j++)
            {
                if(faira == key[i][j] || (faira == 'j' && 'i' == key[i][j]))
                {
                    //탈출문
                    goto returna;
                }
            }
        }
returna:
        for(k = 0 ; k < 5 ; k++)
        {
            for(r = 0 ; r < 5 ; r++)
            {
                if(fairb == key[k][r] || (fairb == 'j' && 'i' == key[k][r]))
                {
                    //탈출문
                    goto returnb;
                }
            }
        }
returnb:

    if(i == k)
    {
        cleartext[cl_index++] = key[i][(5+j-1)%5];
        cleartext[cl_index++] = key[k][(5+r-1)%5];

    }else if( j == r)
    {
         cleartext[cl_index++] = key[(5+i-1)%5][j];
        cleartext[cl_index++] = key[(5+k-1)%5][r];
    }
    else
    {
         cleartext[cl_index++] = key[i][r];
        cleartext[cl_index++] = key[k][j];
    }
}

}// A(65)Z(90) -a(97) 급간32
