// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<string.h>
#include<wchar.h>
#include<locale>
using namespace std;
int main()
{

	_wsetlocale(LC_ALL, L"korean");      //지역화 설정을 전역적으로 적용

	//wcout.imbue(locale("korean"));        //출력시 부분적 적용

	//wcin.imbue(locale("korean"));          //입력시 부분적 적용



	const char* arr = "hello";
	const char* brr = "안녕asdf";

	const wchar_t* crr = L" 안녕핫헤요 asdf ㅗ ㅠ ㅑ ";
	wchar_t drr[20] = { 0, };

	drr[0] = L'안';
	fwprintf(stdout, L"%s\n", drr);
	drr[1] = L'녕';
	drr[2] = L'하';
	fwprintf(stdout, L"%s\n", drr);
	drr[1]++;
	fwprintf(stdout, L"%s\n", drr);

	cout << brr<<'\n';

	fwprintf(stdout, L"%s\n", crr);
	fwprintf(stdout, L"%s\n", L"안녕하세요");

	
	
	cout << strlen(arr) << '\n' << strlen(brr) << '\n' << wcslen(crr) << '\n' << sizeof(crr);

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
