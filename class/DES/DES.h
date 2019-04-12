
#ifndef DES__H__
#define DES__H__

/*

		DES();
		
		DES(bitset<64>keywithparities)
		key값을 넣어준 값으로 설정한후 라운드 키를 생성합니다

		~DES();
		
		void key_generator(bitset<64>& keywithparities)
		void key_generator(uint64_t  keywithparities)
		생성자에서 key값을 설정하지못하거나 재설정할때 사용합니다.
		key값을 넣어준 값으로 설정한후 라운드 키를 생성합니다

		void cipher(const uint64_t &plainblock, uint64_t &cipherblock)
		void cipher(const bitset<64>& plainblock, bitset<64>& cipherblock)

		plainblock으로 넣고 암호화 된값이 cipherblock으로 들어갑니다


		void decrpytion(uint64_t &plainblock, const uint64_t &cipherblock)
		void decrpytion(bitset<64>& plainblock, const bitset<64>& cipherblock)

		cipherblock으로 들어간 암호문을 복호화하여 plainblock에 저장합니다
		
		

		key_value_ull()
		return key unsighed long long
		
		key_value_bit()
		return key bitset<64>

		key_value_string()
		return key string

*/
#include<string>
#include<bitset>

using namespace std;

namespace euns
{
	class DES
	{
	public:
		DES();
		DES(bitset<64>keywithparities);
		DES(uint64_t keywithparities);
		~DES();
		void decrpytion(bitset<64>& plainblock, const bitset<64>& cipherblock); //64 RoundKeyssms 16  48 / 64
		void key_generator(bitset<64>& keywithparities); //const int shifttable[] = shifttables, bitset<48> roundkey[] = RoundKeys);//roundkey는 16 48
		void cipher(const bitset<64>& plainblock, bitset<64>& cipherblock);//64 RoundKeyssms 16  48 / 64

		void decrpytion(uint64_t &plainblock, const uint64_t &cipherblock); //64 RoundKeyssms 16  48 / 64
		void key_generator(uint64_t &keywithparities); //const int shifttable[] = shifttables, bitset<48> roundkey[] = RoundKeys);//roundkey는 16 48
		void cipher(const uint64_t &plainblock, uint64_t &cipherblock);//64 RoundKeyssms 16  48 / 64

		long long key_value_ull();
		bitset<64> key_value_bit();
		string key_value_string();
	private:

		void mixer(bitset<32>& leftblock, bitset<32>& rightblock, bitset<48> roundkey);//48 48 48
		void swapper(bitset<32>& leftblock, bitset<32>& rigthblock); //32 32
		void function(const bitset<32>& inblock, const bitset<48> roundkey, bitset<32>& outblock); // 32  /48/  32
		void substitute(const bitset<48>& inblock, bitset<48>& outblock, const int  substitutiontables[][4][16]); //48 / 48  /8 4 16

		template<size_t bitsize>
		void split(int com_num, int spl_num, const bitset<2 * bitsize>& inblock, bitset<bitsize>& leftblock, bitset<bitsize>& rightblock); //inblock을 왼 오 로 나눈다.

		template<size_t bitsize>
		void combine(int spl_num, int com_num, const bitset<bitsize>& leftblock, const bitset<bitsize>& rightblock, bitset<2 * bitsize>& outblock);

		void copy(int num, const bitset<32>& inBlock, bitset<32>& outBlock);

		template<size_t in_bit_size, size_t out_bit_size>
		void permute(int first_block_num, int final_block_num, const bitset<in_bit_size>& firstblock, bitset<out_bit_size>& finalblock, const int table[]);

		template<size_t bitsize>
		void exclusiveor(int num, const bitset<bitsize>& t1, const bitset<bitsize>& roundkey, bitset<bitsize>& t2); //t1과 rountdey를 xor해서 t2에 저장한다.

		void shiftleft(bitset<28>& block, int numofshifts);

		bitset<64> keywithparity; // 초기 설정 64비트 키값 이값은 직접 설정하는 값이다.

		bitset<48> RoundKeys[16];

		const int initialpermutationtable[64] =
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
		const int finalpermutationtable[64] =
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
		const int expansionpermutationtable[48] =
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


		const int substitutetables[8][4][16] =
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

		const int keycompressiontable[48] =
		{

		14, 17, 11 ,24, 1 ,5 ,3 ,28,
		15, 6 ,21 ,10 ,23 ,19, 12, 4,
		26, 8, 16 ,7 ,27 ,20, 13 ,02,
		41, 52, 31 ,37 ,47 ,55 ,30, 40,
		51 ,45 ,33 ,48 ,44 ,49, 39 ,56,
		34 ,53 ,46 ,42 ,50, 36 ,29 ,32
		};


		int straightpermutationtable[32] =
		{
			16, 7, 20, 21, 29, 12, 28, 17,
			1, 15, 23, 26, 5, 18, 31, 10,
			2, 8, 24, 14, 32, 27, 3, 9,
			19, 13, 30, 6, 22, 11, 4, 25
		};

		const int paritydroptable[64] =
		{
			57,49,41,33,25,17,9,1,
			58,50,42,34,26,18,10,2,
			59,51,43,35,27,19,11,3,
			60,52,44,36,63,55,47,39,
			31,23,15,7,62,54,46,38,
			30,22,14,6,61,53,45,37,
			29,21,13,5,28,20,12,4
		};

		const int shifttables[16] =
		{
			1,1,2,2,
			2,2,2,2,
			1,2,2,2,
			2,2,2,1
		};
	};


	void DES::cipher(const bitset<64>& plainblock, bitset<64>& cipherblock)//64 RoundKeyssms 16  48 / 64
	{
		if (keywithparity.to_ullong() == 0) //0xAABB09182736CCDD
		{
			keywithparity = 0xAABB09182736CCDD;
			key_generator(keywithparity);
		}
		bitset<32> leftblock, rightblock;
		bitset<64>  inblock, outblock;

		permute(64, 64, plainblock, inblock, initialpermutationtable); //plainblock이 pbox를 통해서 inblock 으로 옮긴다
		split(64, 32, inblock, leftblock, rightblock);

		for (int round = 1; round <= 16; round++)
		{
			mixer(leftblock, rightblock, RoundKeys[round - 1]);
			if (round != 16)
			{
				swapper(leftblock, rightblock);
			}
		}

		combine(32, 64, leftblock, rightblock, outblock);

		permute(64, 64, outblock, cipherblock, finalpermutationtable);

	}


	void DES::mixer(bitset<32>& leftblock, bitset<32>& rightblock, bitset<48> roundkey)//32 32 32
	{
		bitset<32> t1, t2, t3;
		copy(32, rightblock, t1);
		function(t1, roundkey, t2);
		exclusiveor(32, leftblock, t2, t3);
		copy(32, t3, leftblock);
	}


	void DES::swapper(bitset<32>& leftblock, bitset<32>& rigthblock) //32 32
	{
		bitset<32> t;
		copy(32, leftblock, t);
		copy(32, rigthblock, leftblock);
		copy(32, t, rigthblock);
	}


	void DES::function(const bitset<32>& inblock, const bitset<48> roundkey, bitset<32>& outblock) // 32  /48/  32
	{
		bitset<48> t1, t2, t3;
		permute(32, 48, inblock, t1, expansionpermutationtable);
		exclusiveor(48, t1, roundkey, t2);
		substitute(t2, t3, substitutetables);
		permute(32, 32, t3, outblock, straightpermutationtable);
	}


	void DES::substitute(const bitset<48>& inblock, bitset<48>& outblock, const int substitutiontables[][4][16]) //48 / 48  /8 4 16
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
	void DES::split(int com_num, int spl_num, const bitset<2 * bitsize>& inblock, bitset<bitsize>& leftblock, bitset<bitsize>& rightblock) //inblock을 왼 오 로 나눈다.
	{
		for (int i = 0; i < spl_num; i++)
		{
			rightblock[i] = inblock[i];
			leftblock[i] = inblock[i + spl_num];
		}
	}
	template<size_t in_bit_size, size_t out_bit_size>
	void DES::permute(int first_block_num, int final_block_num, const bitset<in_bit_size>& firstblock, bitset<out_bit_size>& finalblock, const int table[])
	{
		for (int i = 0; i < final_block_num; i++)
		{
			finalblock[i] = firstblock[table[i] - 1];
		}
	}


	template<size_t bitsize>
	void DES::combine(int spl_num, int com_num, const bitset<bitsize>& leftblock, const bitset<bitsize>& rightblock, bitset<2 * bitsize>& outblock)
	{
		for (int i = 0; i < spl_num; i++)
		{
			outblock[i] = rightblock[i];
			outblock[i + spl_num] = leftblock[i];
		}
	}

	void DES::copy(int num, const bitset<32>& inBlock, bitset<32>& outBlock)
	{
		for (int i = 0; i < num; i++)
		{
			outBlock[i] = inBlock[i];
		}
	}


	template<size_t bitsize>
	void DES::exclusiveor(int num, const bitset<bitsize>& t1, const bitset<bitsize>& roundkey, bitset<bitsize>& t2) //t1과 rountdey를 xor해서 t2에 저장한다.
	{
		for (int i = 0; i < num; i++)
		{
			t2[i] = t1[i] ^ roundkey[i];
		}
	}

	///////////////////////////////////////////////////////////////////////////
	//키생성


	void DES::key_generator(bitset<64>& keywithparities) //const int shifttable[], bitset<48> roundkey[])//roundkey는 16 48
	{
		keywithparity = keywithparities;

		bitset<56> cipherkey;
		bitset<28>  leftkey, rightkey;


		permute(64, 56, keywithparities, cipherkey, paritydroptable); //축소 p박스
		split(56, 28, cipherkey, leftkey, rightkey);
		for (int round = 0; round < 16; round++)
		{
			bitset<56> preroundkey;
			shiftleft(leftkey, shifttables[round]);
			shiftleft(rightkey, shifttables[round]);
			combine(28, 56, leftkey, rightkey, preroundkey);
			permute(56, 48, preroundkey, RoundKeys[round], keycompressiontable);
		}
	}

	void DES::shiftleft(bitset<28>& block, int numofshifts)
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

	void DES::decrpytion(bitset<64>& plainblock, const bitset<64>& cipherblock) //64 RoundKeyssms 16  48 / 64
	{
		bitset<32> leftblock, rightblock;
		bitset<64> inblock, outblock;

		permute(64, 64, cipherblock, inblock, initialpermutationtable); //plainblock이 pbox를 통해서 inblock 으로 옮긴다

		split(64, 32, inblock, leftblock, rightblock);

		for (int round = 16; round > 0; round--)
		{
			mixer(leftblock, rightblock, RoundKeys[round - 1]);
			if (round != 1)
				swapper(leftblock, rightblock);
		}

		combine(32, 64, leftblock, rightblock, outblock);

		permute(64, 64, outblock, plainblock, finalpermutationtable);
	}

	long long DES::key_value_ull()
	{
		return keywithparity.to_ullong();
	}
	bitset<64> DES::key_value_bit()
	{
		return keywithparity;
	}
	string DES::key_value_string()
	{
		return keywithparity.to_string();
	}

	DES::DES() 
	{	 
	}
	DES::DES(bitset<64>keywithparities) : keywithparity(keywithparities)
	{
		key_generator(keywithparities);
	}
	DES::~DES()
	{

	}
	DES::DES(uint64_t keywithparities)
	{

	}

	void DES::decrpytion(uint64_t &plainblock, const uint64_t &cipherblock) //64 RoundKeyssms 16  48 / 64
	{
		const bitset<64> _cipherblock = cipherblock;
		bitset<64> _plainblock = plainblock;
		bitset<32> leftblock, rightblock;
		bitset<64> inblock, outblock;

		permute(64, 64, _cipherblock, inblock, initialpermutationtable); //plainblock이 pbox를 통해서 inblock 으로 옮긴다

		split(64, 32, inblock, leftblock, rightblock);

		for (int round = 16; round > 0; round--)
		{
			mixer(leftblock, rightblock, RoundKeys[round - 1]);
			if (round != 1)
				swapper(leftblock, rightblock);
		}

		combine(32, 64, leftblock, rightblock, outblock);

		permute(64, 64, outblock, _plainblock, finalpermutationtable);
		plainblock = _plainblock.to_ullong();
	}





	void DES::key_generator(uint64_t &keywithparities) //const int shifttable[] = shifttables, bitset<48> roundkey[] = RoundKeys);//roundkey는 16 48
	{
		keywithparity = keywithparities;

		bitset<56> cipherkey;
		bitset<28>  leftkey, rightkey;


		permute(64, 56, keywithparity, cipherkey, paritydroptable); //축소 p박스
		split(56, 28, cipherkey, leftkey, rightkey);
		for (int round = 0; round < 16; round++)
		{
			bitset<56> preroundkey;
			shiftleft(leftkey, shifttables[round]);
			shiftleft(rightkey, shifttables[round]);
			combine(28, 56, leftkey, rightkey, preroundkey);
			permute(56, 48, preroundkey, RoundKeys[round], keycompressiontable);
		}
	}

	void DES::cipher(const uint64_t &plainblock, uint64_t &cipherblock)//64 RoundKeyssms 16  48 / 64
	{
		bitset<64> _cipherblock = cipherblock;
		const bitset<64> _plainblock = plainblock;

		if (keywithparity.to_ullong() == 0) //0xAABB09182736CCDD
		{
			keywithparity = 0xAABB09182736CCDD;
			key_generator(keywithparity);
		}
		bitset<32> leftblock, rightblock;
		bitset<64>  inblock, outblock;

		permute(64, 64, _plainblock, inblock, initialpermutationtable); //plainblock이 pbox를 통해서 inblock 으로 옮긴다
		split(64, 32, inblock, leftblock, rightblock);

		for (int round = 1; round <= 16; round++)
		{
			mixer(leftblock, rightblock, RoundKeys[round - 1]);
			if (round != 16)
			{
				swapper(leftblock, rightblock);
			}
		}

		combine(32, 64, leftblock, rightblock, outblock);

		permute(64, 64, outblock, _cipherblock, finalpermutationtable);
		cipherblock = _cipherblock.to_ullong();
	}
	
}
#endif