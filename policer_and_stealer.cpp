
// 연인 코니와 브라운은 광활한 들판에서 나잡아봐라 게임을 한다 이 게임은 브라운이 코니를 잡거나 코니가 너무 멀리 달아나면 끝난다 게임이 끝나는데 걸리는 최소시간을 구하시오

// 코니는 처음 위치에서 1초후 1만큼  움직이고 이 후에는 가속이 붙어 매 초 마다 이전 이동거리 +1 만큼 움직인다. 즉 시간에 따른 코니의 위치는 c  c+1 c+3 c+6이다.
// 브라운은 현재 위치 B에서 다음 순간 B-1 B+1 2*B중 하나로 이동할 수 있다.
// 코니와 브라운의 위치 x는 0<=x <=200,000이다.
// 브라운은 범위를 벗어나는 위치로는 이동할 수 없고, 코니가 범위를 벗어나면 게임이 끝난다
// 브라운이 코니를 잡을 수 있는 최소 시간 N초의 N을 표준 출력에 쓴다.

// 브라운이 코니를 잡지 못한 상태로 게임이 끝나면 표준 출력에 -1을 쓴다.

// 입력 11 2
// 출력 5

// 코니의 위치 11 12 14 17 21 26
// 브라운 2 3 6 12 13 26
// 브라운은 코니를 5초만에 잡을 수 있다.

//cony: 첫위치
// brown : 브라운 첫위치

#include<queue>
#include<iostream>
using namespace std;

int BFS(int cony , int brown)
{
    queue<int> Q;
    Q.push(brown);
    int _cony = cony;
    int _time=-1;//단계별 cony 추가 거리
    while(!Q.empty())
    {
        unsigned int number = Q.size();
        //_cony += _time += 1; //????
        _time += 1;
        _cony += _time;

        for(unsigned int  i = 0 ;  i < number ; i++ )
        {
            int _brown = Q.front();
            if(_brown == _cony)
            {
                //cout << _time << endl;
                return _time;
            }

            Q.pop();

            if(_brown < 0 || _brown > 200000 || _cony < 0 || _cony > 200000)
            {
                continue;
            }

            Q.push(_brown+1);
            Q.push(_brown-1);
            Q.push(_brown*2);
        }


    }
    //cout << -1 << endl;
    return -1;
}

int main()
{
    int Max = 0;
    for(int i = 0;  i <= 200000;i ++)
    {    
        for(int j = 0;  j <= 200000; j ++)
            {
                int max = BFS(i , j);
                if( Max < max)
                {
                    Max = max;
                }
            }
    }
    cout <<" max타임" <<Max << endl;
    return 0;
}

/*

#include<queue>
#include<iostream>
using namespace std;

void BFS(int cony , int brown)
{
    queue<int> Q;
    Q.push(brown);
    int _cony = cony;
    int _time=-1;//단계별 cony 추가 거리
    while(!Q.empty())
    {
        unsigned int number = Q.size();
        //_cony += _time += 1; //????
        _time += 1;
        _cony += _time;

        for(unsigned int  i = 0 ;  i < number ; i++ )
        {
            int _brown = Q.front();
            if(_brown == _cony)
            {
                cout << _time << endl;
                return ;
            }

            Q.pop();

            if(_brown < 0 || _brown > 200000 || _cony < 0 || _cony > 200000)
            {
                continue;
            }

            Q.push(_brown+1);
            Q.push(_brown-1);
            Q.push(_brown*2);
        }


    }
    cout << -1 << endl;
    return ;
}





int main()
{
    BFS(11 , 2);
    return 0;
}



*/
