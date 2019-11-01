#include <iostream>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string str1("C:\\Users\\owner\\Desktop\\김상현\\총포\\");
    string str2(".txt") ;
ofstream out("out.txt");
    const int num = 191000;
for(int i = 2 ; i <= 31;i++)
{


    string str3 = str1 +  to_string(num+i) + "\\"  + to_string(num+i)+ str2  ;
    cout<< str3 <<endl;
    string buffer;
    ifstream in(str3);

    if (!in.is_open())
    {
        cout <<"x"<<endl;
        continue;
    }
    while(!in.eof())
     {
         in >> buffer;
     cout << buffer << endl;
    out << buffer << endl;
     }

    in.close();

}
    out.close();


    return 0;
}
