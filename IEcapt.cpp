#include <iostream>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<windows.h>
using namespace std;
int main()
{
//    cout << "오늘 날짜  191105등으로 입력 ";
//    int date
//    cin date ;
//
//    //cout<<amd <<'\n';
//    int i = 1;
//    ifstream in("address.txt");
//    if(!in.is_open())
//    {
//        cout<< "파일없음 ";
//    }
//    int n = 0;
//    while(!in.eof())
//    {
//        string amd;
//        in >> amd;
//        string cm = "IECapt --url="
//        + amd +" --out=" + to_string(date+n)+"\\" + to_string(i) +".png";
//    //cout << cm<<'\n';
//
//    const char* len = cm.c_str();
//    cout << len<<'\n';
//
//    string mk = "mkdir "+ to_string(191103+n);
//    system(mk.c_str());
//
//    system(len);
//    if(i == 1)
//    {
//        i++;
//    }
//    else
//    {
//        i = 1;
//        n++;
//    }
//    cout << i <<'\n';
//    }


    cout << "오늘 날짜  191105등으로 입력 ";
    int date;
    cin >> date ;

    //cout<<amd <<'\n';
    int i = 1;
    ifstream in("address.txt");
    if(!in.is_open())
    {
        cout<< "파일없음 ";
    }
    int n = 0;
    //while(!in.eof())
    {
        string amd;
        cin >> amd;
        string cm = "IECapt --url="
        + amd +" --out=" + to_string(date+n)+"/" + to_string(i) +".png";
    //cout << cm<<'\n';

    const char* len = cm.c_str();
    cout << len<<'\n';

    string mk = "mkdir "+ to_string(date+n);
    system(mk.c_str());

    system(len);
    if(i == 1)
    {
        i++;
    }
    else
    {
        i = 1;
        n++;
    }
    cout << i <<'\n';
    }
    return 0;
}
