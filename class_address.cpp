#include <iostream>
using namespace std;


class A
{
private :
	char a;
	int b;
	char c;


public:
	A(char aa = 0, int bb = 0, char cc = 0)  : a(aa), b(bb) ,c(cc)
	{ cout << "A생성자 호출" << endl; }
	~A()
	{
		cout << "A소멸자 호출" << endl;
	}
	void a_ptr()
	{
		cout << "A simple.a의 주소" << &a << endl;
	}
	void b_ptr()
	{
		cout << "A simple.b의 주소" << &b << endl;
	}
	void c_ptr()
	{
		cout << "A simple.c의 주소" << &c << endl;
	}
};

class B : public A
{
private :
	double aa;
	int bb;
	char cc;

public:
	B(double a = 0 , int b = 0, char c = 0) : aa(a), bb(b), cc(c) 
	{ cout << "B생성자 호출" << endl; }
	~B()
	{
		cout << "B소멸자 호출" << endl;
	}
	void aa_ptr()
	{
		cout << "B simple.aa의 주소" << &aa << endl;
	}
	void bb_ptr()
	{
		cout << "B simple.bb의 주소" << &bb << endl;
	}
	void cc_ptr()
	{
		cout << "B simple.cc의 주소" << &cc << endl;
	}
};






int main()
{
	cout << "Hello, World!"<< endl;

	B simple;
	

	cout << "sizeof double 의 크기" << sizeof(double) << endl;
	cout << "sizeof int 의 크기" << sizeof(int) << endl;
	cout << "sizeof char* 의 크기" << sizeof(char*) << endl;

	cout << "simple 의 주소" << &simple << endl;
	cout << "simple의 크기" << sizeof(simple) << endl;
	cout << endl;
	simple.aa_ptr();
	simple.bb_ptr();
	simple.cc_ptr();
	simple.a_ptr();
	simple.b_ptr();
	simple.c_ptr();


	system("pause");
	return 0;
}