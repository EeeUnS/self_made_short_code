#define SR_NS_BEGIN(NS)     namespace NS {
#define SR_NS_END(NS)       }

#ifdef _XUTILITY_
#define ASSERT(expr, ...) if(!(expr)) __asm{ int 3 }
#else
#define ASSERT(expr, ...) 
#endif // DEBUG

SR_NS_BEGIN(euns)
SR_NS_END(euns)

//current if multiplication calculation exceeds 128 digits, program dead because memory allocation.
//TODO memory Optimization

#include<memory>
#include<string>
#include<istream>
#include<ostream>
#include<iostream>
#include<string.h>
#include<complex>
#include<vector>
#include<assert.h>
#include<algorithm>

typedef std::complex<long double> base;
constexpr double PI = 3.14159265358979323846;


class bigint{
public:
	bigint();
	bigint(const char* const a);
	bigint(const std::string& a);

	bigint(std::int8_t a); // 8 bit char
	bigint(std::int16_t a); // 16bit short
	bigint(std::int32_t a); //32bit int
	bigint(std::int64_t a); // 64bit long long int
	bigint(std::uint64_t a); // 64bit std::uint64_t

	//copy 
	bigint& operator=(const bigint& a);
	bigint& operator=(const std::string& a);
	bigint& operator=(std::int64_t a);
	bigint& operator=(std::uint64_t a);

	bigint(const bigint& a);
	//move
	bigint& operator=(bigint&& a) noexcept;
	bigint(bigint&& a) noexcept;
	~bigint();

	const bigint operator+(const bigint& a) const;
	const bigint operator-(const bigint& a) const;
	const bigint operator-() const; // -this ¹ÝÈ¯
	const bigint operator*(const bigint& a) const;// using fft
	const bigint operator/(const bigint& a) const;
	const bigint operator%(const bigint& a) const;
	bigint& operator+=(const bigint& a);
	bigint& operator-=(const bigint& a);
	bigint& operator*=(const bigint& a);
	bigint& operator/=(const bigint& a);
	bigint& operator%=(const bigint& a);

	bigint& operator++();
	bigint operator++(int);
	bigint& operator--();
	bigint operator--(int);

	bool operator==(std::int64_t a) const;
	bool operator!=(std::uint64_t  a) const;


	bool operator==(const bigint& a) const;
	bool operator!=(const bigint& a) const;
	bool operator>(const bigint& a) const;
	bool operator<(const bigint& a) const;
	bool operator>=(const bigint& a) const;
	bool operator<=(const bigint& a) const;

	friend std::ostream& operator<<(std::ostream& os, const bigint& a);
	friend std::istream& operator>>(std::istream& os, bigint& a);
private:
	void fft(std::vector<base>& inOutF, bool invert) const;

private:
	std::unique_ptr<char[]> mString; // default 128
	int mLength; // 
	int mCapacity; //default 128
	bool mSign;//+ : true - : false 
};


bigint::bigint() : bigint(0)
{}

bigint::bigint(const std::string& a) : bigint(a.c_str())
{}

bigint::bigint(const char* a) : mCapacity(128), mLength(0), mString(), mSign(true)
{
	int numLength = 0;
	int havingSign = 0;

	if (*a == '-')
	{
		mSign = false;
		++havingSign;
	}
	if (*a == '+')
	{
		++havingSign;
	}
	char reg = 0;
	while ((reg = *(a + havingSign + numLength)) != '\0')
	{
		if ('0' > reg || '9' < reg)
		{
			std::cout << "not number" << std::endl;
			return;
		}
		++numLength;
	}

	mLength = numLength;
	mCapacity = 128;
	while (numLength > mCapacity)
	{
		mCapacity <<= 1;
	}

	mString = std::make_unique<char[]>(mCapacity);

	// i = 1 or 0
	for (int j = 0; j < numLength; j++)
	{
		mString[j] = *(a + numLength + havingSign - 1 - j) - '0';
	}
}


bigint::bigint(std::int8_t a) : bigint((std::int64_t)a)
{}

bigint::bigint(std::int16_t a) : bigint((std::int64_t)a)
{}

bigint::bigint(std::int32_t a) : bigint((std::int64_t)a)
{}

bigint::bigint(std::int64_t a) // 64bit long long int
{
	mCapacity = 128;
	mString = std::make_unique<char[]>(mCapacity);
	std::int64_t b = a;
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



bigint::bigint(std::uint64_t a) :mCapacity(128), mSign(true)
// 64bit std::uint64_t
{
	mString = std::make_unique<char[]>(mCapacity);
	std::uint64_t b = a;
	int i = 0;
	while (b)
	{
		mString[i] = b % 10;
		b /= 10;
		i++;
	}
	mLength = i;
}

// copy constructor
bigint::bigint(const bigint& a) : mCapacity(a.mCapacity), mSign(a.mSign), mString(nullptr), mLength(a.mLength)
{
	//std::cout << "using copy constructor" << std::endl;
	mString = std::make_unique<char[]>(mCapacity);
	memcpy(mString.get(), a.mString.get(), mCapacity);
}

bigint::~bigint()
{
}


bigint& bigint::operator=(const bigint& a)
{
	//std::cout << "nomal assignment operator" << '\n';
	if (&a == this)
	{
		return *this;
	}

	if (mCapacity != a.mCapacity)
	{
		mCapacity = a.mCapacity;
		mString.reset();
		mString = std::make_unique<char[]>(mCapacity);
	}
	mSign = a.mSign;
	mLength = a.mLength;
	memcpy(mString.get(), a.mString.get(), mCapacity);

	return *this;
}

bigint& bigint::operator=(std::int64_t a)
{
	return (*this = bigint(a));
}

bigint& bigint::operator=(std::uint64_t a)
{
	return (*this = bigint(a));
}

bigint& bigint::operator=(const std::string& a)
{
	return (*this = bigint(a));
}

bigint& bigint::operator=(bigint&& a) noexcept
{
	//	std::cout << "move assignment operator" << std::endl;
	mString = std::move(a.mString);
	mSign = (a.mSign);
	mLength = (a.mLength);
	mCapacity = (a.mCapacity);
	a.mString = nullptr;
	return *this;
}

bigint::bigint(bigint&& a)noexcept : mSign(a.mSign), mLength(a.mLength), mCapacity(a.mCapacity)
{
	//	std::cout << "move constructor" << std::endl;
	mString = std::move(a.mString);
}

// only this procedure sign same
const bigint bigint::operator+(const bigint& a) const
{
	if (a.mSign != mSign)
	{
		return *this - a;
	}
	bigint tmp;
	tmp.mSign = a.mSign;
	tmp.mCapacity = a.mCapacity > mCapacity ? a.mCapacity : mCapacity;
	if ((a.mCapacity == a.mLength) || (mCapacity == mLength))
	{
		tmp.mCapacity *= 2;
	}
	if (tmp.mCapacity > 128)
	{
		tmp.mString.reset(new char[tmp.mCapacity]());
	}

	tmp.mLength = a.mLength > mLength ? a.mLength : mLength;
	int carry = 0;
	int Length = tmp.mLength;
	for (int i = 0; i < Length; i++)
	{
		carry = mString[i] + a.mString[i] + carry;
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

// only this procedure sign deffernt
const bigint bigint::operator-(const bigint& a) const
{
	if (a.mSign != mSign)
	{
		return *this + a;
	}
	bigint tmp;
	const bigint* b;
	if (a == *this)
	{
		tmp.mSign = true;
		tmp.mLength = 1;
		return tmp;
	}

	if (*this > a)
	{
		tmp = *this;
		b = &a;
	}
	else
	{
		tmp = a;
		tmp.mSign = !tmp.mSign;
		b = this;
	}
	const int len = b->mLength;
	for (int i = len; i >= 0; --i)
	{
		tmp.mString[i] -= b->mString[i];
		int j = 0;

		while (tmp.mString[i + j] < 0)
		{
			tmp.mString[i + j] += 10;
			--tmp.mString[i + j + 1];
			++j;
		}
		if (tmp.mString[tmp.mLength - 1] == 0)
		{
			--tmp.mLength;
		}
	}

	return tmp;

}

const bigint bigint::operator-() const
{
	//	std::cout << "test ";
	bigint tmp = *this;
	tmp.mSign = !mSign;
	return tmp;
}


// base multiply n^2
//const bigint bigint::operator*(const bigint& a) const
//{
//	if (a == 0)
//	{
//		return bigint(0);
//	}
//	bigint tmp;
//	tmp.mSign = false;//-
//	if (a.mSign == mSign)
//	{
//		tmp.mSign = true;//+
//	}
//	tmp.mCapacity = a.mCapacity > mCapacity ? a.mCapacity * 2 : mCapacity * 2;
//	delete[]tmp.mString;
//	tmp.mString = new char[tmp.mCapacity]();
//	tmp.mLength = a.mLength + mLength - 1;
//	int aLength = a.mLength;
//	int thisLength = mLength;
//	int carry = 0;
//	for (int i = 0; i < aLength; ++i)
//	{
//		for (int j = 0; j < thisLength; ++j)
//		{
//			carry = mString[j] * a.mString[i] + carry;
//			tmp.mString[i + j] += carry % 10;
//			carry /= 10;
//		}
//		tmp.mString[i + thisLength] += carry;
//	}
//	if (carry != 0)
//	{
//		++tmp.mLength;
//	}
//	return tmp;
//}


const bigint bigint::operator*(const bigint& a) const
{
	if (a.mLength == 0 || this->mLength == 0)
	{
		return bigint(0);
	}

	std::vector <base> fa(mString.get(), mString.get() + mLength), fb(a.mString.get(), a.mString.get() + a.mLength);
	int n = 1;
	while (n < mLength + a.mLength)
	{
		n <<= 1;
	}
	fa.resize(n);
	fb.resize(n);
	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; i++)
	{
		fa[i] *= fb[i];
	}
	fft(fa, true);

	std::vector<int> res;
	res.resize(n);
	for (int i = 0; i < n; i++)
	{
		res[i] = (int)round(fa[i].real());
	}

	while (!res.empty() && res.back() == 0)
	{
		res.pop_back();
	}

	for (int i = 0; i < (int)res.size() - 1; i++)
	{
		if (i == res.size() - 1)
		{
			if (res[i] >= 10)
			{

				res.push_back(res[res.size() - 1] / 10);
				res[res.size() - 2] %= 10;
			}
		}
		else {
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
	}
	bigint tmp;
	tmp.mSign = (a.mSign == mSign);
	if (tmp.mCapacity < n)
	{
		tmp.mString.reset(new char(mCapacity));
	}

	assert((int)strlen(mString.get()) < n);
	for (int i = 0; i < (int)res.size(); i++)
	{
		tmp.mString[i] = (char)res[i];
	}

	tmp.mLength = res.size();

	return tmp;
}

void bigint::fft(std::vector<base>& inOutF, bool invert) const
{
	const int n = inOutF.size();
	for (int i = 1, j = 0; i < n; i++)
	{
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
		{
			j -= bit;
		}
		j += bit;
		if (i < j)
		{
			swap(inOutF[i], inOutF[j]);
		}
	}
	for (int len = 2; len <= n; len <<= 1)
	{
		double ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len)
		{
			base w(1);
			for (int j = 0; j < len / 2; j++)
			{
				base u = inOutF[i + j];
				base v = inOutF[i + j + len / 2] * w;
				inOutF[i + j] = u + v;
				inOutF[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}

	if (invert)
	{
		for (int i = 0; i < n; i++)
		{
			inOutF[i] /= n;
		}
	}
}

/*
base divide
*/
const bigint bigint::operator/(const bigint& a) const
{
	if (mLength < a.mLength)
	{
		return bigint();
	}

	const int aLen = a.mLength;
	const int thisLen = mLength;

	bigint digit = 0;
	for (int i = 0; i < aLen; ++i)
	{
		digit = digit * 10 + mString[thisLen - i - 1];
	}
	bigint tmp;
	for (int i = thisLen - aLen; i >= 0; --i)
	{
		digit = digit * 10 + mString[i];
		int j = 9;
		while (j > 0)
		{
			bigint reg = a * j;
			if (digit - reg > 0)
			{
				digit -= reg;
				tmp += j;
				break;
			}
			--j;
		}
		tmp *= 10;
	}
	return tmp;
}


const bigint bigint::operator%(const bigint& a) const
{
	if (mLength < a.mLength)
	{
		return bigint(*this);
	}

	const int aLen = a.mLength;
	const int thisLen = mLength;

	bigint digit = 0;
	for (int i = 0; i < aLen; ++i)
	{
		digit = digit * 10 + mString[thisLen - i - 1];
	}
	bigint tmp;
	for (int i = thisLen - aLen; i >= 0; --i)
	{
		digit = digit * 10 + mString[i];
		int j = 9;
		while (i > 0)
		{
			bigint reg = a * j;
			if (digit - reg > 0)
			{
				digit -= reg;
				tmp += j;
				break;
			}
			--j;
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
	if ((a.mCapacity == a.mLength) || (mCapacity == mLength))
	{
		mCapacity *= 2;
		std::unique_ptr<char[]> tmp = std::make_unique< char[]>(mCapacity);
		int len = mLength;
		for (int i = 0; i < len; i++)
		{
			tmp[i] = mString[i];
		}
		mString.release();
		mString = std::move(tmp);
	}

	int carry = 0;
	const int Length = mLength;
	for (int i = 0; i < Length; i++)
	{
		carry = mString[i] + a.mString[i] + carry;
		mString[i] = carry % 10;
		carry /= 10;
	}
	if (carry != 0)
	{
		assert(Length < mCapacity);
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
}


bigint& bigint::operator/=(const bigint& a)
{
	return (*this = *this / a);
}


bigint& bigint::operator%=(const bigint& a)
{
	return (*this = *this % a);
}

bigint& bigint::operator++()
{
	return (*this += 1);
}


bigint bigint::operator++(int)
{
	bigint tmp = *this;
	++(*this);
	return tmp;
}

bigint& bigint::operator--()
{
	return (*this -= 1);
}
bigint bigint::operator--(int)
{
	bigint tmp = *this;
	--(*this);
	return tmp;

}

bool bigint::operator==(std::int64_t a) const
{
	return *this == bigint(a);
}

bool bigint::operator!=(std::uint64_t  a) const
{
	return *this != bigint(a);
}


bool bigint::operator==(const bigint& a) const
{
	if (mSign != a.mSign)
	{
		return false;
	}
	if (mLength != a.mLength)
	{
		return false;
	}
	return memcmp(mString.get(), a.mString.get(), mCapacity) == 0;
}
bool bigint::operator!=(const bigint& a) const
{
	return !(*this == a);
}


bool bigint::operator>(const bigint& a) const
{
	if (mSign ^ a.mSign)
	{
		return mSign;
	}

	if (mLength != a.mLength)
	{
		return mLength > a.mLength;
	}

	return memcmp(mString.get(), a.mString.get(), mCapacity) == 0;
}
bool bigint::operator<(const bigint& a) const
{
	if (mSign ^ a.mSign)
	{
		return !mSign;
	}

	if (mLength != a.mLength)
	{
		return mLength < a.mLength;
	}
	return memcmp(mString.get(), a.mString.get(), mCapacity) < 0;
}

bool bigint::operator>=(const bigint& a) const
{
	return !(*this < a);
}
bool bigint::operator<=(const bigint& a) const
{
	return !(*this > a);
}





std::ostream& operator<<(std::ostream& os, const bigint& a)
{

	const int len = a.mLength;
	if (len == 0)
	{
		os << 0;
		return os;
	}

	if (a.mSign == false)
	{
		os << '-';
	}
	for (int i = 0; i < len; i++)
	{
		os << (int)(a.mString[len - 1 - i]);
	}
	return os;
}
std::istream& operator>>(std::istream& os, bigint& a)
{
	std::string tmp;
	os >> tmp;
	a = tmp;
	return os;
}

char arr[30000002];
int main()
{

#ifdef _XUTILITY_
	freopen("input.txt", "r", stdin);
#endif // DEBUG

	std::cin >> arr;
	std::cout << strlen(arr) << '\n';
	bigint a(arr);
	//memset(arr, 0, sizeof(arr));
	std::cin >> arr;
	bigint b(arr);
	bigint c(a + b);
	std::cout << c;

	return 0;
}
