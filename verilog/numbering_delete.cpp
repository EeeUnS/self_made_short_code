#include<string>
#include<cstring>
#include<fstream>
#include<ostream>
#include<iostream>
#include<cstring>

using namespace std;

constexpr int  n = 580;

int main()
{
    std::ofstream out("verilog.v");
    std::ifstream in("verilog.v.txt");
    char str[200] ;
    while(in)
    {
        in.getline(str, 200);
        strtok(str, " " );

//        if( (char *)(str+strlen(str)+1) == '\0')
//        {
//            cout <<"chekcing"<<'\n';
//            cout <<'\n';
//        }
//        else
            {//out << (char*)(str+strlen(str)+1) << '\n';
             out << (char*)(str+strlen(str)+1)<<'\n';
            }
            memset(str, 0 , 200);
    }
    in.close();
    out.close();
    return 0;
}
