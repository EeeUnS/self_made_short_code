#define SR_NS_BEGIN(NS)     namespace NS {
#define SR_NS_END(NS)       }

SR_NS_BEGIN(euns)
SR_NS_END(euns)

#include<string>
#include<istream>
#include<fstream>
#include<iostream>

class bigint //char형 배열 각 자릿수마다 
{
public:
	bigint();
	bigint(const char* a);
	// bigint(const char a); // 8 bit std::int8_t
	// bigint(const short a); // 16bit std::int16_t
	bigint(const int a); //32bit std::int32_t
	bigint(const long long a); // 64bit std::int64_t

	~bigint();


	const bigint operator+(const bigint& a) const ;
	const bigint operator-(const bigint& a) const ;
	const bigint operator-() const;

	//O(n^2)후에 카라추바로 개선
	bigint operator*(const bigint& a) const;
	
	bigint operator/(const bigint& a) const;
	bigint operator%(const bigint& a) const;

	bigint &operator=(const bigint& a) ;
	bigint(const bigint &a) ;

	bigint &operator=(bigint&& a) noexcept ;
	bigint(bigint &&a) noexcept;

	// bigint operator=(const char* a);
	// bigint operator=(const int a);
	// bigint operator=(const char a);
	// bigint operator=(const short a);
	// bigint operator=(const long long int a);
	// bigint operator=(const long int a);

	bool operator==(const bigint& a);
	bool operator>(const bigint& a);
	bool operator<(const bigint& a);
	
	friend std::ostream& operator<<(std::ostream& os, const bigint& a);
    
    friend bool operator==(const bigint& a, const bigint& b);
	friend bool operator>(const bigint& a, const bigint& b);
	friend bool operator<(const bigint& a, const bigint& b);


private:
	char* mString; // default 128
	int mLength; // default 자릿수 길이
	int mCapacity; //default 128
	bool mSign;//+ : true - : false 여부 결정 
};

//0으로 default mLength가 1이고 mString[0]이 0인지 확인
bigint::bigint() : mLength(1), mCapacity(128), mSign(true), mString(nullptr)
{
	mString = new char[128]();
}


bigint::bigint(const char* a) : mCapacity(128), mLength(0),mString(nullptr),mSign(true)
{
	int length = 0;
	int i = 0; // 두번째 반복문의 시작점을 위한 i -,+가 있을시에 한칸 올리고 시작한다.

	if (*a == '-')
	{
		mSign = false;
		++length;
		++i;
	}
	if (*a == '+')
	{
		++length;
		++i;
	}
	int reg = 0;
	while ((reg = *(a + length)) != '\0')
	{
		if ('0' > reg || '9' < reg)
		{
			std::cout << "not number" << std::endl; // 값이 제대로 있지않습니다.
			return;
		}
		++length;
	}

	mLength = length;
	mString = new char[128]();
	mCapacity = 128;

	// i = 1 or 0
	for (int j = 0; i < length; i++, j++)
	{
		mString[j] = *(a + i) - '0';
	}
}



// bigint::bigint(const char a) // 8 bit std::int8_t
// {
// 	mString = new char[128]();
// 	mCapacity = 128;
// 	char b = a;
// 	mSign = true;
// 	if (b < 0)
// 	{
// 		b = -b;
// 		mSign = false;
// 	}
// 	int i = 0;
// 	while (b)
// 	{
// 		mString[i] = b % 10;
// 		b /= 10;
// 		i++;
// 	}
// 	mLength = i;

// }

// bigint::bigint(const short a) // 16bit std::int16_t
// {
// 	mString = new char[128]();
// 	mCapacity = 128;
// 	short b = a;
// 	mSign = true;
// 	if (b < 0)
// 	{
// 		b = -b;
// 		mSign = false;
// 	}
// 	int i = 0;
// 	while (b)
// 	{
// 		mString[i] = b % 10;
// 		b /= 10;
// 		i++;
// 	}
// 	mLength = i;
// }

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

bigint::~bigint()
{
	delete[]mString;
}


bool bigint::operator==(const bigint& a)
{
    if( this->mSign != a.mSign)
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
        if (this->mString[i] != a.mString[i])
		{
			return false;
		}
    }
    return true;
}



bool bigint::operator>(const bigint& a)
{
	// if(this->mSign !=  a.mSign)
	// {
	// 	return this->mSign >  a.mSign;
	// }
	if( this->mSign == true && a.mSign == false)
	{
		return true;
	}
	if(this->mSign == false && a.mSign == true)
	{
		return false;
	}
	//두 부호가 같다.
	// if(this->mLength ^ a.mLength)
	// {
	// 	return this->mLength > a.mLength
	// }

	if(this->mLength > a.mLength)
	{
		return true;
	}
	if(this->mLength < a.mLength)
	{
		return false;
	}
	//length same
	for(int i = mLength ;  i >= 0  ;--i)
	{
		if (this->mString[i] != a.mString[i])
		{
			return this->mString[i] > a.mString[i];
		}
	}
}
bool bigint::operator<(const bigint& a)
{
	// if(this->mSign !=  a.mSign)
	// {
	// 	return this->mSign >  a.mSign;
	// }
	if( this->mSign == true && a.mSign == false)
	{
		return false;
	}
	if(this->mSign == false && a.mSign == true)
	{
		return true;
	}
	//두 부호가 같다.
	// if(this->mLength ^ a.mLength)
	// {
	// 	return this->mLength > a.mLength
	// }

	if(this->mLength > a.mLength)
	{
		return false;
	}
	if(this->mLength < a.mLength)
	{
		return true;
	}
	//length same
	for(int i = mLength ;  i >= 0  ;--i)
	{
		if (this->mString[i] != a.mString[i])
		{
			return this->mString[i] < a.mString[i];
		}
	}
}
//friend
bool operator==(const bigint& a, const bigint& b)
{
    if( a.mSign != b.mSign)
	{
		return false;
	}
	if(a.mLength != b.mLength)
	{
		return false;
	}
    // 부호도같고 길이도같다.
    for(int i = a.mLength ; i >= 0 ; --i)
    {
        if (a.mString[i] != b.mString[i])
		{
			return false;
		}
    }
    return true;
}
bool operator>(const bigint& a, const bigint& b)
{
	// if(a.mSign !=  b.mSign)
	// {
	// 	return a.mSign >  b.mSign;
	// }
	if( a.mSign == true && b.mSign == false)
	{
		return true;
	}
	if(a.mSign == false && b.mSign == true)
	{
		return false;
	}
	//두 부호가 같다.
	// if(a.mLength ^ b.mLength)
	// {
	// 	return a.mLength > b.mLength
	// }

	if(a.mLength > b.mLength)
	{
		return true;
	}
	if(a.mLength < b.mLength)
	{
		return false;
	}
	//length same
	for(int i = a.mLength ;  i >= 0  ;--i)
	{
		if (a.mString[i] != b.mString[i])
		{
			return a.mString[i] > b.mString[i];
		}
	}
}
bool operator<(const bigint& a, const bigint& b)
{
	// if(a.mSign !=  b.mSign)
	// {
	// 	return a.mSign >  b.mSign;
	// }
	if( a.mSign == true && b.mSign == false)
	{
		return false;
	}
	if(a.mSign == false && b.mSign == true)
	{
		return true;
	}
	//두 부호가 같다.
	// if(a.mLength ^ b.mLength)
	// {
	// 	return a.mLength > b.mLength
	// }

	if(a.mLength > b.mLength)
	{
		return false;
	}
	if(a.mLength < b.mLength)
	{
		return true;
	}
	//length same
	for(int i = a.mLength ;  i >= 0  ;--i)
	{
		if (a.mString[i] != b.mString[i])
		{
			return a.mString[i] < b.mString[i];
		}
	}
}

bigint& bigint::operator=(bigint&& a) noexcept
{
	std::cout << "이동 =" << std::endl;
	mString = a.mString;
	mSign = (a.mSign);
	mLength = (a.mLength);
	mCapacity = (a.mCapacity);
	return *this;
}
bigint::bigint(bigint&& a)noexcept :mString(a.mString), mSign(a.mSign), mLength(a.mLength), mCapacity(a.mCapacity)
{
	std::cout << "이동 생성자 호출 !" << std::endl;
	a.mString = nullptr;
}

// + , -를 sign 부호가 같고 다르고로 나눈다.


const bigint bigint::operator+(const bigint& a) const //sign이 같을때 +한다.
{
	if (a.mSign != this->mSign)
	{
		return *this - a;
	}
	bigint tmp;
	tmp.mSign = a.mSign;
	tmp.mCapacity = a.mCapacity > this->mCapacity ? a.mCapacity : this->mCapacity;
	if ((a.mCapacity == a.mLength) || (this->mCapacity == this->mLength)) //overflow고려안해도됨
	{
		tmp.mCapacity *= 2;
	}
	if (tmp.mCapacity > 128)
	{
		delete[]tmp.mString;
		tmp.mString = new char[tmp.mCapacity]();
	}

	tmp.mLength = a.mLength > this->mLength ? a.mLength : this->mLength;
	int carry = 0;
	int Length = tmp.mLength;
	for (int i = 0; i < Length; i++)
	{
		carry = this->mString[i] + a.mString[i] + carry;
		tmp.mString[i] = carry % 10;
		carry /= 10;
	}
	if (carry != 0)
	{
		tmp.mString[Length] = carry;
		tmp.mLength++;
	}
	return tmp;
}


const bigint bigint::operator-(const bigint& a) const
{
	if (a.mSign != this->mSign)
	{
		return *this + a;
	}
	//same sign.
	//큰값을 구하고 작은 값을 뺀후에 부호를 결정한다.
    bigint tmp;
    const bigint *b;
    if( a == *this)
    {
        tmp.mSign = true;
        tmp.mLength = 1;
        return tmp;
    }
    
    if(*this > a)
    {
        tmp = *this;
        b = &a;
    }
    else
    {
        tmp = a;
        tmp.mSign = !tmp.mSign; // 뒤의 절댓값이 더크다.
        b = this;
    }
    const int len = b->mLength;
    for(int i = len ; i >= 0; --i)
    {
        tmp.mString[i] -=  b->mString[i];
        int j = 0;
        
        while(tmp.mString[i+j] < 0) // 음수처리 tmp.mLength바뀔수있음
        {
            tmp.mString[i+j] += 10;
            --tmp.mString[i+j+1];
            ++j;
        }
        if(tmp.mString[tmp.mLength-1] == 0)
        {
            --tmp.mLength;
        }
    }
    
    return tmp;

}

const bigint bigint::operator-() const
{
    std::cout << "test " ; 
	bigint tmp = *this;
	tmp.mSign = !this->mSign;
	return tmp;
}

/*
a*b=c  sign
++ +
+- -
-+ -
-- +
*/
bigint bigint::operator*(const bigint& a) const
{
	bigint tmp;
	tmp.mSign = false;//-
	if (a.mSign == this->mSign)
	{
		tmp.mSign = true;//+
	}
	tmp.mCapacity = a.mCapacity > this->mCapacity ? a.mCapacity * 2 : this->mCapacity * 2;
	delete[]tmp.mString;
	tmp.mString = new char[tmp.mCapacity]();
	tmp.mLength = a.mLength + this->mLength - 1;
	int aLength = a.mLength;
	int thisLength = this->mLength;
	int carry = 0;
	for (int i = 0; i < aLength; ++i)
	{
		for (int j = 0; j < thisLength; ++j)
		{
			carry = this->mString[j] * a.mString[i] + carry;
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



bigint bigint::operator/(const bigint& a) const 
{
    // a/b 
    bigint tmp = *this;
    if( tmp < a )
    {
        return tmp;
    }

}

//bigint bigint::operator%(const bigint& a)
//{
//
//}
//
//
//bigint bigint::operator=(const bigint& a)
//{
//
//}




std::ostream& operator<<(std::ostream& os, const bigint& a)
{
	const int len = a.mLength;
	if (a.mSign == false)
	{
		os << '-';
	}
	for (int i = 0; i < len; i++)
	{
		os << static_cast<int>(a.mString[i]);
	}
	return os;
}


bigint &bigint::operator=(const bigint& a)
{
	std::cout << "일반 대입연산자" << '\n';
	 if (&a == this )
       {return *this;}
	if(this->mCapacity != a.mCapacity)
	{
		this->mCapacity = a.mCapacity;
		delete[]this->mString;
		this->mString = new char[a.mCapacity]();
	}
	this->mSign = a.mSign;
	int len = this->mLength = a.mLength;
	for(int i = 0 ; i < len ; i++)
	{
		this->mString[i] = a.mString[i];
	}
	

	return *this;
}
bigint::bigint(const bigint &a) : mCapacity(128) , mSign(true), mString(nullptr),mLength(0)
{
	std::cout << "복사생성자사용" << '\n';
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

// bigint operator=(const char* a);
// bigint operator=(const int a);
// bigint operator=(const char a);
// bigint operator=(const short a);
// bigint operator=(const long long int a);
// bigint operator=(const long int a);

int main()
{
	bigint a("1111");
	bigint b("2222");
	
	bigint c = a * b;
    if(a>b)
    {
        std::cout << c << '\n';    
    }
	std::cout << c << '\n';


	return 0;
}
