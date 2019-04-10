﻿
#include "pch.h"


#include<bitset>
using namespace std;


int keyWithParities[64];// 초기 설정 64비트 키값 이값은 직접 설정하는 값이다.

const int InitialPermutationTable[64] =
{
	58, 50, 42, 34, 26,18,10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7
};
//마지막 P BOX
const int FinalPermutationTable[64] =
{
	40, 8, 48, 16, 56, 24, 64, 32,
	39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41, 9, 49, 17, 57, 25
};

//라운드 내부
const int ExpansionPermutationTable[48] =
{
	32, 1, 2, 3, 4, 5,
	4, 5, 6, 7, 8, 9,
	8, 9, 10, 11, 12, 13,
	12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21,
	20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29,
	28, 29, 30, 31, 32, 1
};


const int SubstituteTables[8][4][16] =
{
	{
		{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
		{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
		{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
		{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 2, 14, 10, 0, 6, 13}
	},

	{
		{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
		{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
		{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
		{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
	},

	{
		{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
		{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
		{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
		{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
	},

	{
		{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
		{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
		{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
		{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
	},

	{
		{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
		{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
		{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
		{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
	},

	{   {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
		{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
		{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
		{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
	},

	{
		{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
		{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
		{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
		{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
	},

	{
		{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
		{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
		{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
		{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
	}
};

int KeyCompressionTable[48] =
{

14, 17, 11 ,24, 1 ,5 ,3 ,28,
15, 6 ,21 ,10 ,23 ,19, 12, 4,
26, 8, 16 ,7 ,27 ,20, 13 ,02,
41, 52, 31 ,37 ,47 ,55 ,30, 40,
51 ,45 ,33 ,48 ,44 ,49, 39 ,56,
34 ,53 ,46 ,42 ,50, 36 ,29 ,32
};


int StraightPermutationTable[32] =
{
	16, 7, 20, 21, 29, 12, 28, 17,
	1, 15, 23, 26, 5, 18, 31, 10,
	2, 8, 24, 14, 32, 27, 3, 9,
	19, 13, 30, 6, 22, 11, 4, 25
};

//static??
int RoundKeys[16][48] = { 0, };



const int ParityDropTable[64] =
{
	57,49,41,33,25,17,9,1,
	58,50,42,34,26,18,10,2,
	59,51,43,35,27,19,11,3,
	60,52,44,36,63,55,47,39,
	31,23,15,7,62,54,46,38,
	30,22,14,6,61,53,45,37,
	29,21,13,5,28,20,12,4
};

const int ShiftTable[16] =
{
	1,1,2,2,
2,2,2,2,
	1,2,2,2,
	2,2,2,1
};
///////////////////////////////////////////////////////////////////////////

void Cipher(int plainBlock[], int RoundKey[][48], int cipherBlock[]);//64 RoundKeyssms 16  48 / 64
void mixer(int leftBlock[], int  rightBlock[], int RoundKey[]);//48 48 48
void swapper(int leftBlock[], int  rigthBlock[]); //32 32
void function(int inBlock[], int RoundKey[], int outBlock[]); // 32  /48/  32
void substitute(int inBlock[], int  outBlock[], const int  SubstitutionTables[][4][16]); //48 / 48  /8 4 16
void split(int com_num, int spl_num, int  inBlock[], int leftBlock[], int rightBlock[]); //inblock을 왼 오 로 나눈다.
void combine(int spl_num, int com_num, int leftBlock[], int rightBlock[], int outBlock[]);
void copy(int num, int rightBlock[], int T1[]);
void permute(int first_Block_num, int final_Block_num, int firstBlock[], int finalBlock[], const int Table[]);
void exclusiveOr(int num, int T1[], int RoundKey[], int T2[]); //T1과 rountdey를 xor해서 T2에 저장한다.
void Key_Generator(int keyWithParities[], int RoundKey[][48], const int ShiftTable[]);//roundkey는 16 48
void shiftLeft(int block[], int numOfShifts);
void Decrpytion(int plainBlock[], int RoundKey[][48], int cipherBlock[]); //64 RoundKeyssms 16  48 / 64

void print(int arr[])
{
	for (int i = 0; i < 16; i++)
	{
		cout << arr[i];
		if ((i + 1) % 8 == 0)
			cout << " ";
	}
	cout << "\n";
}

int main()
{
	for (int i = 0; i < 16 ; i++)
	{
		for (int j = 0; j < 48; j++)
		{
			RoundKeys[i][j] = 1;
		}
	}
	int key[64] = { 0, };
	//Key_Generator(key ,RoundKeys , ShiftTable);
	int plainBlock[64] =
	{
		0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1
	};
	int cipherBlock[64] = { 0, };
	int replainBock[64] = { 0, };
	print(plainBlock);
	Cipher(plainBlock, RoundKeys, cipherBlock);
	print(cipherBlock);
	Decrpytion(replainBock, RoundKeys, cipherBlock);
	print(replainBock);

	return 0;
}
void Cipher(int plainBlock[], int RoundKey[][48], int cipherBlock[])//64 RoundKeyssms 16  48 / 64
{
	int leftBlock[32] = { 0, }, rightBlock[32] = { 0, };
	int inBlock[64] = { 0, }, outBlock[64] = { 0, };

	permute(64, 64, plainBlock, inBlock, InitialPermutationTable); //plainblock이 pbox를 통해서 inblock 으로 옮긴다 

	split(64, 32, inBlock, leftBlock, rightBlock);

	for (int round = 1; round <= 16; round++)
	{
		mixer(leftBlock, rightBlock, RoundKey[round - 1]);
		if (round != 16)
			swapper(leftBlock, rightBlock);
	}

	combine(32, 64, leftBlock, rightBlock, outBlock);

	permute(64, 64, outBlock, cipherBlock, FinalPermutationTable);

}


void mixer(int leftBlock[], int  rightBlock[], int roundkey[])//48 48 48
{
	int T1[32] = { 0, }, T2[32] = { 0, }, T3[32] = { 0, };
	copy(32, rightBlock, T1);
	function(T1, roundkey, T2);
	exclusiveOr(32, leftBlock, T2, T3);
	copy(32, T3, leftBlock);
}


void swapper(int leftBlock[], int  rigthBlock[]) //32 32
{
	int T[32] = { 0, };
	copy(32, leftBlock, T);
	copy(32, rigthBlock, leftBlock);
	copy(32, T, rigthBlock);
}


void function(int inBlock[], int RoundKey[], int outBlock[])// 32 48,  32
{
	int T1[32] = {0,}, T2[32] = { 0, }, T3[32] = { 0, };
	permute(32, 48, inBlock, T1, ExpansionPermutationTable);
	exclusiveOr(48, T1, RoundKey, T2);
	substitute(T2, T3, SubstituteTables);
	permute(32, 32, T3, outBlock, StraightPermutationTable);
}


void substitute(int inBlock[], int  outBlock[], const int  SubstitutionTables[][4][16]) //48 / 48  /8 4 16
{
	for (int i = 0; i < 8; i++)
	{
		int row = 2 * inBlock[i * 6 + 0] + inBlock[i * 6 + 5];
		int col = 8 * inBlock[i * 6 + 1] + 4 * inBlock[i * 6 + 2] + 2 * inBlock[i * 6 + 3] + inBlock[i * 6 + 4];
		int value = SubstitutionTables[i][row][col];
		outBlock[i * 4 + 0] = value / 8;
		value = value % 8;
		outBlock[i * 4 + 1] = value / 4;
		value = value % 4;
		outBlock[i * 4 + 2] = value % 2;
		value = value % 2;
		outBlock[i * 4 + 3] = value;
	}
}


void split(int com_num, int spl_num, int  inBlock[], int leftBlock[], int rightBlock[]) //inblock을 왼 오 로 나눈다.
{
	for (int i = 0; i < spl_num; i++)
	{
		rightBlock[i] = inBlock[i];
		leftBlock[i] = inBlock[i + spl_num];
	}
}

void permute(int first_Block_num, int final_Block_num, int firstBlock[], int finalBlock[], const int Table[])
{
	for (int i = 0; i < final_Block_num; i++)
	{
		finalBlock[i] = firstBlock[Table[i] - 1];
	}
}

void combine(int spl_num, int com_num, int leftBlock[], int rightBlock[], int outBlock[])
{
	for (int i = 0; i < spl_num; i++)
	{
		outBlock[i] = rightBlock[i];
		outBlock[i + spl_num] = leftBlock[i];
	}
}

void copy(int num, int rightBlock[], int T1[])
{
	for (int i = 0; i < num; i++)
	{
		T1[i] = rightBlock[i];
	}
}

void exclusiveOr(int num, int T1[], int RoundKey[], int T2[]) //T1과 rountdey를 xor해서 T2에 저장한다.
{
	for (int i = 0; i < num; i++)
	{
		T2[i] = T1[i] ^ RoundKey[i];
	}
}

///////////////////////////////////////////////////////////////////////////
//키생성

void Key_Generator(int keyWithParities[], int RoundKey[][48], const int ShiftTable[])//roundkey는 16 48
{
	int cipherKey[56] = { 0, }, leftKey[28] = { 0, }, rightKey[28] = { 0, };


	permute(64, 56, keyWithParities, cipherKey, ParityDropTable); //축소 P박스 
	split(56, 28, cipherKey, leftKey, rightKey);
	for (int round = 0; round < 16; round++)
	{
		int preRoundKey[56];
		shiftLeft(leftKey, ShiftTable[round]);
		shiftLeft(rightKey, ShiftTable[round]);
		combine(28, 56, leftKey, rightKey, preRoundKey);
		permute(56, 48, preRoundKey, RoundKey[round], KeyCompressionTable);
	}
}

void shiftLeft(int block[], int numOfShifts)
{
	for (int i = 0; i < numOfShifts; i++)
	{
		int T = block[0];
		for (int j = 1; j < 28; j++)
		{
			block[j - 1] = block[j];
		}
		block[27] = T;
	}

}

///////////////////////////////////////////////////////////

void Decrpytion(int plainBlock[], int RoundKeys[][48], int cipherBlock[]) //64 RoundKeyssms 16  48 / 64
{
	int leftBlock[32] = { 0, }, rightBlock[32] = { 0, };
	int inBlock[64] = { 0, }, outBlock[64] = { 0, };

	permute(64, 64, cipherBlock, inBlock, InitialPermutationTable); //plainblock이 pbox를 통해서 inblock 으로 옮긴다 

	split(64, 32, inBlock, leftBlock, rightBlock);

	for (int round = 16; round > 0; round--)
	{
		mixer(leftBlock, rightBlock, RoundKeys[round - 1]);
		if (round != 16)
			swapper(leftBlock, rightBlock);
	}

	combine(32, 64, leftBlock, rightBlock, outBlock);

	permute(64, 64, outBlock, plainBlock, FinalPermutationTable);

}
