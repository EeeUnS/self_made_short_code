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
	{ cout << "A������ ȣ��" << endl; }
	~A()
	{
		cout << "A�Ҹ��� ȣ��" << endl;
	}
	void a_ptr()
	{
		cout << "A simple.a�� �ּ�" << &a << endl;
	}
	void b_ptr()
	{
		cout << "A simple.b�� �ּ�" << &b << endl;
	}
	void c_ptr()
	{
		cout << "A simple.c�� �ּ�" << &c << endl;
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
	{ cout << "B������ ȣ��" << endl; }
	~B()
	{
		cout << "B�Ҹ��� ȣ��" << endl;
	}
	void aa_ptr()
	{
		cout << "B simple.aa�� �ּ�" << &aa << endl;
	}
	void bb_ptr()
	{
		cout << "B simple.bb�� �ּ�" << &bb << endl;
	}
	void cc_ptr()
	{
		cout << "B simple.cc�� �ּ�" << &cc << endl;
	}
};






int main()
{
	cout << "Hello, World!"<< endl;

	B simple;
	

	cout << "sizeof double �� ũ��" << sizeof(double) << endl;
	cout << "sizeof int �� ũ��" << sizeof(int) << endl;
	cout << "sizeof char* �� ũ��" << sizeof(char*) << endl;

	cout << "simple �� �ּ�" << &simple << endl;
	cout << "simple�� ũ��" << sizeof(simple) << endl;
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