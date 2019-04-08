
#include "pch.h"
//#include"queue.hpp"

using namespace std;
int b[] = { 12,10 ,43,43 ,23,-78,123,56,45,123 ,56,56,98,45,123,56,98,41,90,24 ,45};//,-78,45,

template<typename T>
void printarr(T a[], int num);

int main()
{
	euns::queue<int> arr;

	for (int i = 0; i < 10; i++)
	{
		arr.push(i);
	}
	cout << arr.empty() << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << arr.front()<< " ";
		arr.pop();
	}
	cout << endl << arr.empty() << endl;

	return 0;
}

template<typename T>
void printarr(T a[], int num)
{
	for (int i = 0; i < num; i++)
		cout << a[i] << " ";
	cout << endl;
}
