#include"string.hpp"
#include<cstring>


namespace euns
{
	int String::num_Strings = 0;

	//static메소드
	int String::HowMany()
	{
		return num_Strings;
	}
	//클래스 메소드

	String::String(const char* s)
	{
		len = std::strlen(s);
		str = new char[len + 1];
		std::strcpy(str, s);
		num_Strings++;
	}

	String::String()
	{
		len = 4;
		str = new char[1];
		str[0] = '\0';
		num_Strings++;
	}

	String::String(const String& st)
	{
		num_Strings++;
		len = st.len;
		str = new char[len + 1];
		std::strcpy(str, st.str);
	}

	String::~String()
	{
		--num_Strings;
		delete[] str;
	}
	//오버로드 연산자 메소드

	String& String::operator=(const String& st)
	{
		if (this == &st)
			return *this;
		delete[] str;
		len = st.len;
		str = new char[len + 1];
		std::strcpy(str, st.str);
		return *this;
	}

	String& String::operator=(const char* s)
	{
		delete[] str;
		len = std::strlen(s);
		str = new char[len + 1];
		std::strcpy(str, s);
		return *this;
	}

	char& String::operator[] (int i)
	{
		return str[i];
	}

	const char& String::operator[] (int i) const
	{
		return str[i];
	}

	bool operator<(const String & st1, const String & st2)
	{
		return (std::strcmp(st1.str, st2.str) < 0);
	}
	bool operator>(const String & st1, const String & st2)
	{
		return st1.str > st2.str;
	}
	bool operator==(const String & st1, const String & st2)
	{
		return (std::strcmp(st1.str, st2.str) == 0);
	}
	ostream& operator<<(ostream & os, const String & st)
	{
		os << st.str;
		return os;
	}
	istream& operator>>(istream & is, String & st)
	{
		char temp[String::CINLIN];
		is.get(temp, String::CINLIN);
		is.get(temp, String::CINLIN);
		if (is)
			st = temp;
		while (is && is.get() != '\n')
			continue;
		return is;
	

	void String::clear()
	{
		;
		// TODO: 여기에 구현 코드 추가.
	}


	bool String::empty()
	{
		// TODO: 여기에 구현 코드 추가.
		return false;
	}


//	char& String::at()
//	{
//		// TODO: 여기에 구현 코드 추가.
//		// TODO: 여기에 반환 구문을 삽입합니다.
//	}


	char& String::at(int i)
	{
		// TODO: 여기에 구현 코드 추가.
		// TODO: 여기에 반환 구문을 삽입합니다.
	}


	char* String::c_str()
	{
		// TODO: 여기에 구현 코드 추가.
		return nullptr;
	}


	char& String::front()
	{
		// TODO: 여기에 구현 코드 추가.
		// TODO: 여기에 반환 구문을 삽입합니다.
	}


	char& String::back()
	{
		// TODO: 여기에 구현 코드 추가.
		// TODO: 여기에 반환 구문을 삽입합니다.
	}
}
