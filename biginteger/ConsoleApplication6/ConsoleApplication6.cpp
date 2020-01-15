#define SR_NS_BEGIN(NS)     namespace NS {
#define SR_NS_END(NS)       }

SR_NS_BEGIN(euns)
SR_NS_END(euns)

#include<string>
#include<istream>
#include<ostream>
#include<iostream>
#include <assert.h>

// 128 변수로 바꾸기
class bigint //char형 배열 각 자릿수마다
{
public:
	bigint();
	bigint(const char a[]);
	bigint(const std::string& a);
	bigint(const char a); // 8 bit std::int8_t
	bigint(const int a); //32bit std::int32_t
	bigint(long long a); // 64bit std::int64_t
	bigint(unsigned long long a); // 64bit std::uint64_t
	// bigint(const short a); // 16bit std::int16_t


	//copy
	bigint &operator=(const bigint& a);
	bigint &operator=(const std::string& a);
	//bigint &operator=(const char a[]);
	bigint &operator=(int a);
	bigint &operator=(char a);
	bigint &operator=(long long a);
	bigint &operator=(unsigned long long a);

	bigint(const bigint &a) ;
	//move
	bigint &operator=(bigint&& a) noexcept ;
	bigint(bigint &&a) noexcept;
	~bigint();


	const bigint operator+(const bigint& a) const ;
	const bigint operator-(const bigint& a) const ;
	const bigint operator-() const; // -this 반환
	const bigint operator*(const bigint& a) const;//O(n^2)후에 카라추바로 개선
	const bigint operator/(const bigint& a) const;
	const bigint operator%(const bigint& a) const;
	bigint& operator+=(const bigint& a);
	bigint& operator-=(const bigint& a);
	bigint& operator*=(const bigint& a);//O(n^2)후에 카라추바로 개선
	bigint& operator/=(const bigint& a);
	bigint& operator%=(const bigint& a);

	//전위증가
	bigint& operator++();
	bigint operator++(int);
	//전위감소
	bigint& operator--();
	bigint operator--(int);

	bool operator==(const bigint& a) const ;
	bool operator!=(const bigint& a) const ;
	bool operator>(const bigint& a) const ;
	bool operator<(const bigint& a) const ;
	bool operator>=(const bigint& a) const ;
	bool operator<=(const bigint& a) const ;



	// integer
	// const bigint operator+(int a) const;
	// const bigint operator-(int a) const;
	// const bigint operator*(int a) const;//O(n^2)후에 카라추바로 개선
	// const bigint operator/(int a) const;
	// const bigint operator%(int a) const;
	// bigint& operator+=(int a);
	// bigint& operator-=(int a);
	// bigint& operator*=(int a);//O(n^2)후에 카라추바로 개선
	// bigint& operator/=(int a);
	// bigint& operator%=(int a);

	// bool operator==(const int a) const ;
	// bool operator!=(const int a) const ;
	// bool operator>(const int a) const ;
	// bool operator<(const int a) const ;
	// bool operator>=(const int a) const ;
	// bool operator<=(const int a) const ;

	friend std::ostream& operator<<(std::ostream& os, const bigint& a);
	friend std::istream& operator>>(std::istream& os, bigint& a);

private:
	const bigint sub(const bigint& a) const;
	const bigint add(const bigint& a) const;
	const bigint abs() const;

	char* mString; // default 128
	int mLength; // default 자릿수 길이
	int mCapacity; //default 128
	bool mSign;//+ : true - : false 여부 결정
};

const bigint bigint::abs() const
{
	bigint tmp = *this;
	if(tmp.mSign == false)
	{
		tmp.mSign = true;
	}

	return tmp;
}


//different sign
const bigint bigint::sub(const bigint& a) const
{
    bigint tmp;
    const bigint *b;

    if( a.abs() == this->abs())
    {
        return tmp;
    }
	else if(this->abs() > a.abs())
    {
        tmp = *this;
        b = &a;
    }
    else// this->abs() < a.abs()
    {
        tmp = a;
		if(mSign == a.mSign)
		{
			tmp.mSign = !mSign;
		}
		else
		{
			tmp.mSign = a.mSign;
		}

        b = this;
    }

	assert(tmp.abs() > b->abs());
	//assert(tmp.mSign == );

	const int  slen = b->mLength;
    for(int i = 0 ; i <= slen; ++i)
    {
        tmp.mString[i] -=  b->mString[i];
        // 음수처리 tmp.mLength바뀔수있음
        for(int j = 0; tmp.mString[i+j] < 0; ++j)
        {
			assert(i+j <= tmp.mLength);
            tmp.mString[i+j] += 10;
            --tmp.mString[i+j+1];
        }
    }

	for(int i = 0; tmp.mString[i+slen] < 0; ++i)
	{
		assert(i+slen <= tmp.mLength);
        tmp.mString[i+slen] += 10;
        --tmp.mString[i+slen+1];
	}

	if(tmp.mString[tmp.mLength-1] == 0 )
	{
		--tmp.mLength;
	}

    return tmp;
}

//same sign
const bigint bigint::add(const bigint& a) const
{
	bigint tmp;
	tmp.mSign = mSign;

	int subLen = 0 ;
	char* sstr = nullptr;
	char* lstr = nullptr;

	if(a.mLength == mLength)
	{
		tmp.mCapacity = a.mCapacity;
		tmp.mLength = a.mLength;

		subLen = a.mLength;
		sstr = a.mString;
		lstr = mString;
	}
	else if(a.mLength > mLength)
	{
		tmp.mCapacity = a.mCapacity;
		tmp.mLength = a.mLength;

		subLen = mLength;
		sstr = mString;
		lstr = a.mString;
	}
	else// (a.mLength < mLength)
	{
		tmp.mCapacity = mCapacity;
		tmp.mLength = mLength;

		subLen = a.mLength;
		sstr = a.mString;
		lstr = mString;
	}

	// tmp.mLength == tmp.mCapacity if overflow
	if (tmp.mCapacity > 128 || tmp.mLength == tmp.mCapacity)
	{
		delete[]tmp.mString;
		tmp.mCapacity *= 2;
		tmp.mString = new char[tmp.mCapacity]();
	}

	int carry = 0;
	for (int i = 0; i < subLen; i++)
	{
		carry = sstr[i] + lstr[i] + carry;
		tmp.mString[i] = carry % 10;
		carry /= 10;
	}

	for(int i = subLen ; i < tmp.mLength ; ++i)
	{
		carry = lstr[i] + carry;
		tmp.mString[i] = carry % 10;
		carry /= 10;
	}

	//don carry about overflow
	if (carry != 0)
	{
		tmp.mString[tmp.mLength] = carry;
		tmp.mLength++;
	}

	return tmp;
}



//0으로 default mLength가 1이고 mString[0]이 0인지 확인
bigint::bigint() : mLength(1), mCapacity(128), mSign(true), mString(nullptr)
{
	mString = new char[128]();
}

bigint::bigint(const std::string& a):mLength(a.length()),mCapacity(128), mSign(true), mString(nullptr)
{
	int i = 0; //시작점을 위한 i -,+가 있을시에 한칸 올리고 시작한다.
	if (a[0] == '-')
	{
		--mLength;
		mSign = false;
		++i;
		if(a[1] == '\0')
		{
			std::cerr << "input error" << std::endl;
			return ;
		}
	}
	else if (a[0] == '+')
	{
		--mLength;
		++i;
	}

	if(mLength > 128)
	{
		while(mCapacity > mLength)
		{
			mCapacity <<= 1;
		}
		mString = new char[mCapacity]();
	}
	else
	{
		mString = new char[128]();
	}

	// i = 1 or 0
	for (int j = mLength - 1 ; i <= mLength; ++i, --j)
	{
		mString[j] = a[i] - '0';
	}
}


bigint::bigint(const char a[]) : mCapacity(128), mLength(0),mString(nullptr),mSign(true)
{
	int length = 0;
	int i = 0; // 두번째 반복문의 시작점을 위한 i -,+가 있을시에 한칸 올리고 시작한다.

	if(a[0] == '\0')
	{
		return ;
	}

	//sign check
	if (*a == '-')
	{
		mSign = false;
		++length;
		++i;
		if(a[1] == '\0')
		{
			std::cerr << "input error" << std::endl;
			assert(0);
			return ;
		}
	}
	else if (*a == '+')
	{
		++length;
		++i;
	}

	//length check
	char reg = 0;
	while ((reg = a[length]) != '\0')
	{
		if ('0' > reg || '9' < reg)
		{
			std::cerr << "not number" << std::endl; // 값이 제대로 있지않습니다.
			assert(0);
			return;
		}
		++length;
	}

	// i = 1 or 0
	mLength = length - i;

	if(mLength > 128)
	{
		while(mCapacity > mLength)
		{
			mCapacity <<= 1;
		}
		mString = new char[mCapacity]();
	}
	else
	{
		mString = new char[128]();
	}

	// i = 1 or 0
	for (int j = mLength - 1 ; j >= 0; ++i, --j)
	{
		mString[j] = a[i] - '0';
	}
	//std::cerr << "constructor called" <<std::endl;
}


bigint::bigint(const char a):mCapacity(128), mLength(1),mString(nullptr),mSign(true)
{
	mString = new char[128]();
	if( '0'> a && '9' < a )
	{
		std::cerr << "Input error" << std::endl;
		assert(0);
		return ;
	}
	mString[0] = a - '0';
}

bigint::bigint(const int a) //32bit std::int32_t
{
	mString = new char[128]();
	mCapacity = 128;
	int b = a;
	mSign = true;
	if (b < 0)
	{
		b = -b;
		mSign = false;
	}
	int i = 0;
	while (b)
	{
		mString[i] = b % 10;
		b /= 10;
		i++;
	}
	mLength = i;
}

bigint::bigint(const long long a) // 64bit std::int64_t
{
	mString = new char[128]();
	mCapacity = 128;
	long long int b = a;
	mSign = true;
	if (b < 0)
	{
		b = -b;
		mSign = false;
	}
	int i = 0;
	while (b)
	{
		mString[i] = b % 10;
		b /= 10;
		i++;
	}
	mLength = i;
}
bigint::bigint(unsigned long long a) // 64bit std::uint64_t
{
	mString = new char[128]();
	mCapacity = 128;
	long long int b = a;
	mSign = true;
	if (b < 0)
	{
		b = -b;
		mSign = false;
	}
	int i = 0;
	while (b)
	{
		mString[i] = b % 10;
		b /= 10;
		i++;
	}
	mLength = i;
}

bigint::bigint(const bigint &a) : mCapacity(128) , mSign(true), mString(nullptr),mLength(0)
{
	//	std::cerr << "복사생성자사용" << '\n';
	if (this == &a)
       {return ;}
	if(mCapacity != a.mCapacity)
	{
		mCapacity = a.mCapacity;
	}
	mString = new char[a.mCapacity]();
	mSign = a.mSign;
	int len = mLength = a.mLength;
	for(int i = 0 ; i < len ; i++)
	{
		mString[i] = a.mString[i];
	}
}


bigint::~bigint()
{
	//assert(mString != nullptr);
	delete[]mString;
}

bigint &bigint::operator=(const bigint& a)
{
	//std::cerr << "일반 대입연산자" << '\n';
	 if (&a == this )
       {return *this;}
	if(mCapacity != a.mCapacity)
	{
		mCapacity = a.mCapacity;
		delete[]mString;
		mString = new char[a.mCapacity]();
	}
	mSign = a.mSign;
	int len = mLength = a.mLength;
	for(int i = 0 ; i < len ; i++)
	{
		mString[i] = a.mString[i];
	}


	return *this;
}

bigint& bigint::operator=(char a)
{
	return (*this = bigint(a));
}

bigint& bigint::operator=(int a)
{
	return (*this = bigint(a));
}


bigint& bigint::operator=(long long a)
{
	return (*this = bigint(a));
}


bigint& bigint::operator=(unsigned long long a)
{
	return (*this = bigint(a));
}


bigint& bigint::operator=(const std::string& a)
{
	return (*this = bigint(a));
}

bigint& bigint::operator=(bigint&& a) noexcept
{
	//std::cerr << "이동 =" << std::endl;
	mString = a.mString;
	mSign = (a.mSign);
	mLength = (a.mLength);
	mCapacity = (a.mCapacity);
	a.mString = nullptr;
	return *this;
}

bigint::bigint(bigint&& a)noexcept :mString(a.mString), mSign(a.mSign), mLength(a.mLength), mCapacity(a.mCapacity)
{
	//std::cerr << "이동 생성자 호출 !" << std::endl;
	a.mString = nullptr;
}

// (+) : same sign (-) : different sign
const bigint bigint::operator+(const bigint& a) const
{
	if (a.mSign == mSign)
	{
		return add(a);
	}
	else // !=
	{
		return sub(a) ;
	}
}

const bigint bigint::operator-(const bigint& a) const
{
	//same sign.
	if (a.mSign == mSign)
	{
		return sub(a) ;
	}
	else // !=
	{
		return add(a);
	}

}

const bigint bigint::operator-() const
{
    //std::cerr << "test " ;
	bigint tmp = *this;
	tmp.mSign = !mSign;
	return tmp;
}



/*
a*b=c  sign
++ +
+- -
-+ -
-- +
*/
const bigint bigint::operator*(const bigint& a) const
{
	if(a == 0)
	{
		return bigint(0);
	}
	bigint tmp;
	tmp.mSign = false;//-
	if (a.mSign == mSign)
	{
		tmp.mSign = true;//+
	}
	tmp.mCapacity = a.mCapacity > mCapacity ? a.mCapacity * 2 : mCapacity * 2;
	delete[]tmp.mString;
	tmp.mString = new char[tmp.mCapacity]();
	tmp.mLength = a.mLength + mLength - 1;
	int aLength = a.mLength;
	int thisLength = mLength;
	int carry = 0;
	for (int i = 0; i < aLength; ++i)
	{
		for (int j = 0; j < thisLength; ++j)
		{
			carry = mString[j] * a.mString[i] + carry;
			tmp.mString[i + j] += carry % 10;
			carry /= 10;
		}
		tmp.mString[i + thisLength] += carry;
	}
	if (carry != 0)
	{
		++tmp.mLength;
	}
	return tmp;
}


/*
가장 기본적인 나눗셈을 그대로 구현
*/
const bigint bigint::operator/(const bigint& a) const
{
    // a/b
    if( mLength < a.mLength )
    {
        return bigint();
    }

	const int aLen = a.mLength;
	const int thisLen = mLength;

	bigint digit(0) ;
	for(int i = 0 ; i < aLen ; ++i)
	{
		digit = digit *10 + mString[thisLen - i - 1];
	}
	bigint tmp;
	for(int j = thisLen - aLen ; j >= 0  ; --j)
	{
		digit = digit*10 + mString[j];
		int i = 9;
		while(i>0)
		{
			bigint reg = a*i;
			if( digit - reg > 0 )
			{
				digit -= reg;
				tmp += i;
				break;
			}
			--i;
		}
		tmp *= 10;
	}
	return tmp;
}


const bigint bigint::operator%(const bigint& a) const
{
    if( mLength < a.mLength )
    {
        return bigint(*this);
    }

	const int aLen = a.mLength;
	const int thisLen = mLength;

	bigint digit(0) ;
	for(int i = 0 ; i < aLen ; ++i)
	{
		digit = digit *10 + mString[thisLen - i - 1];
	}
	bigint tmp;
	for(int j = thisLen - aLen ; j >= 0  ; --j)
	{
		digit = digit*10 + mString[j];
		int i = 9;
		while(i>0)
		{
			bigint reg = a*i;
			if( digit - reg > 0 )
			{
				digit -= reg;
				tmp += i;
				break;
			}
			--i;
		}
		tmp *= 10;
	}
	return digit;
}

bigint& bigint::operator+=(const bigint& a)
{
	if (a.mSign != mSign)
	{
		return (*this -= a);
	}
	mLength = a.mLength > mLength ? a.mLength : mLength;
	if ((a.mCapacity == a.mLength) || (mCapacity == mLength)) //overflow고려안해도됨
	{
		mCapacity *= 2;
		char *tmp = new char[mCapacity]();
		int len = mLength;
		for(int i = 0 ; i < len ; i++)
		{
			tmp[i] = mString[i];
		}
		delete[]mString;
		mString  = tmp;
	}
	int carry = 0;
	int Length = mLength;
	for (int i = 0; i < Length; i++)
	{
		//bug a.mString < mLength
		carry = mString[i] + a.mString[i] + carry;
		mString[i] = carry % 10;
		carry /= 10;
	}
	if (carry != 0)
	{
		mString[Length] = carry;
		mLength++;
	}
	return *this;
}

bigint& bigint::operator-=(const bigint& a)
{
	return (*this = *this - a);
}
bigint& bigint::operator*=(const bigint& a)
{
	return (*this = *this * a);
}//O(n^2)후에 카라추바로 개선


bigint& bigint::operator/=(const bigint& a)
{
	return (*this = *this / a);
}


bigint& bigint::operator%=(const bigint& a)
{
	return (*this = *this % a);
}


// 	//need
// const bigint bigint::operator+(int a) const
// {
// 	if( (a<0) && mSign)
// 	bigint tmp;
// 	tmp.mSign = a.mSign;
// 	tmp.mCapacity = a.mCapacity > mCapacity ? a.mCapacity : mCapacity;
// 	if ((a.mCapacity == a.mLength) || (mCapacity == mLength)) //overflow고려안해도됨
// 	{
// 		tmp.mCapacity *= 2;
// 	}
// 	if (tmp.mCapacity > 128)
// 	{
// 		delete[]tmp.mString;
// 		tmp.mString = new char[tmp.mCapacity]();
// 	}

// 	tmp.mLength = a.mLength > mLength ? a.mLength : mLength;
// 	int carry = 0;
// 	int Length = tmp.mLength;
// 	for (int i = 0; i < Length; i++)
// 	{
// 		carry = mString[i] + a.mString[i] + carry;
// 		tmp.mString[i] = carry % 10;
// 		carry /= 10;
// 	}
// 	if (carry != 0)
// 	{
// 		tmp.mString[Length] = carry;
// 		tmp.mLength++;
// 	}
// 	return tmp;
// }
// const bigint bigint::operator-(int a) const;
// const bigint bigint::operator*(int a) const;//O(n^2)후에 카라추바로 개선
// const bigint bigint::operator/(int a) const;
// const bigint bigint::operator%(int a) const;
// bigint& bigint::operator+=(int a);
// bigint& bigint::operator-=(int a);
// bigint& bigint::operator*=(int a);//O(n^2)후에 카라추바로 개선
// bigint& bigint::operator/=(int a);
// bigint& bigint::operator%=(int a);


//전위증가
bigint& bigint::operator++()
{
	return (*this +=1);
}


bigint bigint::operator++(int)
{
	bigint tmp = *this;
	++*this;
	return tmp;
}
//전위감소
bigint& bigint::operator--()
{
	return (*this -= 1);
}
bigint bigint::operator--(int)
{
	bigint tmp = *this;
	--*this;
	return tmp;

}


bool bigint::operator==(const bigint& a) const
{
    if( mSign != a.mSign)
	{
		return false;
	}
	if(mLength != a.mLength)
	{
		return false;
	}
    // 부호도같고 길이도같다.
    for(int i = mLength ; i >= 0 ; --i)
    {
        if (mString[i] != a.mString[i])
		{
			return false;
		}
    }
    return true;
}
bool bigint::operator!=(const bigint& a) const
{
	return !(*this == a);
}


bool bigint::operator>(const bigint& a) const
{
	if(mSign^a.mSign)
	{
		return mSign;
	}

	//두 부호가 같다.
	if(mLength != a.mLength)
	{
		return mLength > a.mLength;
	}

	//length same
	for(int i = mLength ;  i >= 0  ;--i)
	{
		if (mString[i] != a.mString[i])
		{
			return mString[i] > a.mString[i];
		}
	}
}
bool bigint::operator<(const bigint& a) const
{
	if(mSign^a.mSign)
	{
		return !mSign;
	}

	//두 부호가 같다.
	if(mLength != a.mLength)
	{
		return mLength < a.mLength;
	}
	//두 부호, length same

	for(int i = mLength ;  i >= 0  ;--i)
	{
		if (mString[i] != a.mString[i])
		{
			return mString[i] < a.mString[i];
		}
	}
}
bool bigint::operator>=(const bigint& a) const
{
	return !(*this < a);
}
bool bigint::operator<=(const bigint& a) const
{
	return !(*this > a);
}

	// const bigint bigint::operator+(int a) const;
	// const bigint bigint::operator-(int a) const;
	// const bigint bigint::operator*(int a) const;//O(n^2)후에 카라추바로 개선
	// const bigint bigint::operator/(int a) const;
	// const bigint bigint::operator%(int a) const;
	// bigint& bigint::operator+=(int a);
	// bigint& bigint::operator-=(int a);
	// bigint& bigint::operator*=(int a);//O(n^2)후에 카라추바로 개선
	// bigint& bigint::operator/=(int a);
	// bigint& bigint::operator%=(int a);



std::ostream& operator<<(std::ostream& os, const bigint& a)
{
	if (a.mSign == false)
	{
		os << '-';
	}

	for (int i = a.mLength - 1 ; i >= 0; --i)
	{
		os << static_cast<int>(a.mString[i]);
	}
	return os;
}

std::istream& operator>>(std::istream& os, bigint& a)
{
	//char str[10005];
	std::string str;
	os >> str;
	a = bigint(str);
	return os;
}

int main()
{

	bigint a,b;
	
	std::cin >> a >> b;
	std::cout << a + b ;


	return 0;
}

	//std::string strr = "1532";

	//bigint a = "10000";
	//bigint b = "2223";
	//bigint c = strr;
	//std::cin >> a >> b;
    //std::cin >> a+b;
	//std::cout << c << std::endl;
	//std::cout <<
	// std::cout << a << '\n' <<b <<'\n';
    // std::cout << b - a <<'\n' << a + b<<"\n ------------------------\n";

    // bigint c = "-12345";
    // bigint d = "-34567";

    // std::cout << c << '\n' << d <<'\n';
    // std::cout << c - d <<'\n' << c + d<<"\n ------------------------\n";
	// //20000 -40000
    // std::cout << a << '\n' << c <<'\n';
    // std::cout << a - c <<'\n' << a + c<<"\n ------------------------\n";

	// // std::cout << (a > c) << std::endl;
////뺄셈 무한루프
//1099511627776 1073741824
//1100585369600
//123456789123456789123456789
//987654321987654321987654321
//1111111111111111111111111110
// 10000
// 2223
// 7777
// 12223
//  ------------------------
// -10000
// -30000
// -20000 -> 20000
// -40000
//  ------------------------
// 10000
// -10000
// -20000 - > 20000
