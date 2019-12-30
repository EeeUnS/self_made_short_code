// consoleapplication7.cpp : this file contains the 'main' function. program execution begins and ends there.
//

#include<vector>
#include<deque>
#include<stack>
#include<queue>
// ConsoleApplication4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

template <int N>
struct Factorial {
	static const int result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<1> {
	static const int result = 1;
};

constexpr long long factorial(long long n)
{
	long long a = 1;
	for (long long i = 2; i <= n; i++)
	{
		a *= i;
	}
	return a;
}

int main()
{
	for (int n = 0; n <= 12; n++)
	{

		
				switch (n)
				{
				case 0:
					std::cout << Factorial<1>::result;
					break;
				case 1:
					std::cout << factorial(1);
					break;
				case 2:
					std::cout << factorial(2);
					break;
				case 3:
					std::cout << factorial(3);
					break;
				case 4:
					std::cout << factorial(4);
					break;
				case 5:
					std::cout << factorial(5);
					break;
				case 6:
					std::cout << factorial(6);
					break;
				case 7:
					std::cout << factorial(7);
					break;
				case 8:
					std::cout << factorial(8);
					break;
				case 9:
					std::cout << factorial(9);
					break;
				case 10:
					std::cout << factorial(10);
					break;
				case 11:
					std::cout << factorial(11);
					break;
				case 12:
					std::cout << factorial(12);
					break;
				default:
					break;
				}
		
/*
		switch (n)
		{
		case 0:
			std::cout << factorial(1);
			break;
		case 1:
			std::cout << factorial(1);
			break;
		case 2:
			std::cout << factorial(2);
			break;
		case 3:
			std::cout << factorial(3);
			break;
		case 4:
			std::cout << factorial(4);
			break;
		case 5:
			std::cout << factorial(5);
			break;
		case 6:
			std::cout << factorial(6);
			break;
		case 7:
			std::cout << factorial(7);
			break;
		case 8:
			std::cout << factorial(8);
			break;
		case 9:
			std::cout << factorial(9);
			break;
		case 10:
			std::cout << factorial(10);
			break;
		case 11:
			std::cout << factorial(11);
			break;
		case 12:
			std::cout << factorial(12);
			break;
		default:
			break;
		}*/
	}
	return 0;

}


/*
	//std::vector<long long> con;
	//
	//constexpr long long j = factorial(0);
	//con.push_back(j);
	//for (int i = 0; i <= 12; i++)
	//{
	//	std::cout << con[i] << std::endl ;
	//}

*/