

#include <iostream>



#include<bitset>

using namespace std;

namespace euns
{
	int keywithparities[64];// 초기 설정 64비트 키값 이값은 직접 설정하는 값이다.

	static const int initialpermutationtable[64] =
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
//	//마지막 p box
	static const int finalpermutationtable[64] =
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
	static const int expansionpermutationtable[48] =
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


	static const int substitutetables[8][4][16] =
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

	static const int keycompressiontable[48] =
	{

	14, 17, 11 ,24, 1 ,5 ,3 ,28,
	15, 6 ,21 ,10 ,23 ,19, 12, 4,
	26, 8, 16 ,7 ,27 ,20, 13 ,02,
	41, 52, 31 ,37 ,47 ,55 ,30, 40,
	51 ,45 ,33 ,48 ,44 ,49, 39 ,56,
	34 ,53 ,46 ,42 ,50, 36 ,29 ,32
	};


	static int straightpermutationtable[32] =
	{
		16, 7, 20, 21, 29, 12, 28, 17,
		1, 15, 23, 26, 5, 18, 31, 10,
		2, 8, 24, 14, 32, 27, 3, 9,
		19, 13, 30, 6, 22, 11, 4, 25
	};


	static bitset<48> roundkeys[16];



	static const int paritydroptable[64] =
	{
		57,49,41,33,25,17,9,1,
		58,50,42,34,26,18,10,2,
		59,51,43,35,27,19,11,3,
		60,52,44,36,63,55,47,39,
		31,23,15,7,62,54,46,38,
		30,22,14,6,61,53,45,37,
		29,21,13,5,28,20,12,4
	};

	static const int shifttable[16] =
	{
		1,1,2,2,
		2,2,2,2,
		1,2,2,2,
		2,2,2,1
	};
	/////////////////////////////////////////////////////////////////////////

	/*
	요구사항 :
	long값이 들어올때 비트셋으로 바꿔준다.
	stirng으로 값이 들어올때 비트셋으로 바꿔준다

	1. 암호화할 값이 들어온다. -> 암호화된 값을 리턴한다
	2. 암호화된 값이 들어온다. -> 복호화된 값을 리턴한다.


	최종적으로는
	*/

	void cipher(bitset<64>& plainblock, bitset<48> roundkey[], bitset<64>& cipherblock);//64 roundkeyssms 16  48 / 64
	static void mixer(bitset<32>& leftblock, bitset<32>& rightblock, bitset<48> roundkey);//48 48 48
	static void swapper(bitset<32>& leftblock, bitset<32>& rigthblock); //32 32
	static void function(bitset<32>& inblock, bitset<48> roundkey, bitset<32>& outblock); // 32  /48/  32
	static void substitute(bitset<48>& inblock, bitset<48>& outblock, const int  substitutiontables[][4][16]); //48 / 48  /8 4 16

	template<size_t bitsize>
	static void split(int com_num, int spl_num, bitset<2* bitsize>& inblock, bitset<bitsize>& leftblock, bitset<bitsize>& rightblock); //inblock을 왼 오 로 나눈다.

	template<size_t bitsize>
	static void combine(int spl_num, int com_num, bitset<bitsize>& leftblock, bitset<bitsize>& rightblock, bitset<2* bitsize>& outblock);

	static void copy(int num, bitset<32>& rightblock, bitset<32>& t1);

	template<size_t in_bit_size, size_t out_bit_size>
	static void permute(int first_block_num, int final_block_num, bitset<in_bit_size>& firstblock, bitset<out_bit_size>& finalblock, const int table[]);

	template<size_t bitsize>
	static void exclusiveor(int num, bitset<bitsize>& t1, bitset<bitsize>& roundkey, bitset<bitsize>& t2); //t1과 rountdey를 xor해서 t2에 저장한다.

	template<size_t bitsize>

	static void key_generator(bitset<64>& keywithparities, bitset<48> roundkey[], const int shifttable[]);//roundkey는 16 48
	static void shiftleft(bitset<28>& block, int numofshifts);

	void decrpytion(bitset<64>& plainblock, bitset<48> roundkey[], bitset<64>& cipherblock); //64 roundkeyssms 16  48 / 64

	void cipher(bitset<64>& plainblock, bitset<48> roundkey[], bitset<64>& cipherblock)//64 roundkeyssms 16  48 / 64
	{
		bitset<32> leftblock, rightblock;
		bitset<64>  inblock, outblock;

		permute(64, 64, plainblock, inblock, initialpermutationtable); //plainblock이 pbox를 통해서 inblock 으로 옮긴다
		split(64, 32, inblock, leftblock, rightblock);

		for (int round = 1; round <= 16; round++)
		{
			mixer(leftblock, rightblock, roundkey[round - 1]);
			if (round != 16)
			{
			    swapper(leftblock, rightblock);
			}
		}

		combine(32, 64, leftblock, rightblock, outblock);

		permute(64, 64, outblock, cipherblock, finalpermutationtable);

	}


	static void mixer(bitset<32>& leftblock, bitset<32>& rightblock, bitset<48> roundkey)//32 32 32
	{
		bitset<32> t1, t2, t3;
		copy(32, rightblock, t1);
		function(t1, roundkey, t2);
		exclusiveor(32, leftblock, t2, t3);
		copy(32, t3, leftblock);
	}


	static void swapper(bitset<32>& leftblock, bitset<32>& rigthblock) //32 32
	{
		bitset<32> t;
		copy(32, leftblock, t);
		copy(32, rigthblock, leftblock);
		copy(32, t, rigthblock);
	}


	static void function(bitset<32>& inblock, bitset<48> roundkey , bitset<32>& outblock) // 32  /48/  32
	{
		bitset<48> t1 , t2, t3;
		permute(32, 48, inblock, t1, expansionpermutationtable);
		exclusiveor(48, t1, roundkey, t2);
		substitute(t2, t3, substitutetables);
		permute(32, 32, t3, outblock, straightpermutationtable);
	}


	static void substitute(bitset<48>& inblock, bitset<48>& outblock, const int  substitutiontables[][4][16]) //48 / 48  /8 4 16
	{
		for (int i = 0; i < 8; i++)
		{
			int row = 2 * inblock[i * 6 + 0] + inblock[i * 6 + 5];
			int col = 8 * inblock[i * 6 + 1] + 4 * inblock[i * 6 + 2] + 2 * inblock[i * 6 + 3] + inblock[i * 6 + 4];
			int value = substitutiontables[i][row][col];
			outblock[i * 4 + 0] = value / 8;
			value = value % 8;
			outblock[i * 4 + 1] = value / 4;
			value = value % 4;
			outblock[i * 4 + 2] = value % 2;
			value = value % 2;
			outblock[i * 4 + 3] = value;
		}
	}


	template<size_t bitsize>
	static void split(int com_num, int spl_num, bitset<2 * bitsize>& inblock, bitset<bitsize>& leftblock, bitset<bitsize>& rightblock) //inblock을 왼 오 로 나눈다.
	{
		for (int i = 0; i < spl_num; i++)
		{
			rightblock[i] = inblock[i];
			leftblock[i] = inblock[i + spl_num];
		}
	}
	template<size_t in_bit_size, size_t out_bit_size>
	static void permute(int first_block_num, int final_block_num, bitset<in_bit_size>& firstblock, bitset<out_bit_size>& finalblock, const int table[])
	{
		for (int i = 0; i < final_block_num; i++)
		{
			finalblock[i] = firstblock[table[i] - 1];
		}
	}


	template<size_t bitsize>
	static void combine(int spl_num, int com_num, bitset<bitsize>& leftblock, bitset<bitsize>& rightblock, bitset<2* bitsize>& outblock)
	{
		for (int i = 0; i < spl_num; i++)
		{
			outblock[i] = rightblock[i];
			outblock[i + spl_num] = leftblock[i];
		}
	}

	static void copy(int num, bitset<32>& rightblock, bitset<32>& t1)
	{
	    for(int i = 0 ; i < num ; i++)
        {
            t1[i] = rightblock[i];
        }
	}


	template<size_t bitsize>
	static void exclusiveor(int num, bitset<bitsize>& t1, bitset<bitsize>& roundkey, bitset<bitsize>& t2) //t1과 rountdey를 xor해서 t2에 저장한다.
	{
		for (int i = 0; i < num; i++)
		{
			t2[i] = t1[i] ^ roundkey[i];
		}
	}

	///////////////////////////////////////////////////////////////////////////
	//키생성


	static void key_generator(bitset<64>& keywithparities, bitset<48> roundkey[], const int shifttable[])//roundkey는 16 48
	{
		bitset<56> cipherkey;
		bitset<28>  leftkey, rightkey;


		permute(64, 56, keywithparities, cipherkey, paritydroptable); //축소 p박스
		split(56, 28, cipherkey, leftkey, rightkey);
		for (int round = 0; round < 16; round++)
		{
			bitset<56> preroundkey;
			shiftleft(leftkey, shifttable[round]);
			shiftleft(rightkey, shifttable[round]);
			combine(28, 56, leftkey, rightkey, preroundkey);
			permute(56, 48, preroundkey, roundkey[round], keycompressiontable);
		}
	}

	static void shiftleft(bitset<28>& block, int numofshifts)
	{
		for (int i = 0; i < numofshifts; i++)
		{
			bitset<1> t(block[0]);
			for (int j = 1; j < 28; j++)
			{
				block[j - 1] = block[j];
			}
			block[27] = t[0];
		}

	}

	///////////////////////////////////////////////////////

	void decrpytion(bitset<64>& plainblock, bitset<48> roundkey[], bitset<64>& cipherblock) //64 roundkeyssms 16  48 / 64
	{
		bitset<32> leftblock, rightblock;
		bitset<64> inblock, outblock;

		permute(64, 64, cipherblock, inblock, initialpermutationtable); //plainblock이 pbox를 통해서 inblock 으로 옮긴다

		split(64, 32, inblock, leftblock, rightblock);

		for (int round = 16; round > 0; round--)
		{
			mixer(leftblock, rightblock, roundkeys[round - 1]);
			if (round != 1)
				swapper(leftblock, rightblock);
		}

		combine(32, 64, leftblock, rightblock, outblock);

		permute(64, 64, outblock, plainblock, finalpermutationtable);
	}

}

using namespace euns ;

int main()
{

	bitset<64> key(0xAABB09182736CCDD);//0xAABB09182736CCDD
	key_generator(key, roundkeys, shifttable);
	bitset<64> plainblock;

	bitset<64>  cipherblock;
	bitset<64>  replainbock;

	cout << plainblock << '\n';
	cipher(plainblock, roundkeys, cipherblock);
	cout << cipherblock << '\n';
	decrpytion(replainbock, roundkeys, cipherblock);
	cout << replainbock << '\n';

	return 0;
}



 /*********************************************************************************** */

