#ifndef MYSTRING_HPP_
#define MYSTRING_HPP_
#include<iostream>

using std::ostream;
using std::istream;

class String

{
private:
    /* data */
    char *str;
    int len;
    static int num_Strings;
    static const int CINLIN = 80;
public:
//생성자 ,기타 메소드
    String();
    String(const char *s);
    String(const String &st);
    ~String();
    int length() const {return len;}
//오버로딩 연산자 메소드
    String &operator=(const String &st);
    String & operator=(const char * s);
    char  & operator[](int i) ;
    const char & operator[] (int i) const;
// 오버로딩 연산자 프렌드
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend ostream & operator<<(ostream & os, const String &st);
    friend istream & operator>>(istream & is, String &st);
//static 함수
    static int HowMany();
};


#endif