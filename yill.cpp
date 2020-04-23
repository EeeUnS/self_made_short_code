#include<string>
#include<cstring>
#include<fstream>
#include<ostream>
#include<iostream>
#include<algorithm>
using namespace std;
#include<stack>
int main()
{
	char a[] = "asdfvb";
	std::ifstream in("새 텍스트 문서 (2).txt");
	std::string s;
	std::string mukai = "{\\pos(871.356,900.942)} ";
	std::string sarha = "{\\pos(1080.707,488.168)}";
	if (!in.is_open())
	{
		std::cout << "not file";
		return 0;
	}

	std::ofstream out("11.txt");
	std::string sec;
	string pos;
	while (in)
	{
		std::getline(in, sec);

		if (sec == "사라")
		{
			pos = sarha;
		}
		else if(sec == "무카이")
		{
			pos = mukai;
		}
		else if (sec == "")
		{
		}
		else
		{
			sec = pos + sec;
		}
		out << sec << '\n';
	}
	in.close();
	out.close();
	return 0;
}
