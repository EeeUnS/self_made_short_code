
// 도둑이 경찰을 잡으러가고있다. 일직선위에서만 움직이며 정확히 같은 위치일때만
// 잡았다고 할수있다.
// 경찰은 처음 위치에서 1초후 1만큼 오른쪽으로 움직이고 이 후 에는 가속이 붙어 계차수열의 등차가 1인 형태로 움직인다. 즉 시간에 따른 경찰의 위치는 
// P P+1 P+3 P+6이다.
// 도둑은 현재 위치 S에서 S+1 S-1 2S중 하나로 이동할 수 있다.
// 도둑과 경찰의 위치 x는  0<=x <=200,000이다.

// 도둑이 경찰을 잡을 수 있는 최소 시간 N초의 N을 표준 출력에 쓴다.
// 도둑은 범위를 벗어나는 위치로는 이동할 수 없고, 경찰이 범위를 벗어나면 게임이 끝난다

// 도둑이 경찰를 잡지 못한 상태로 게임이 끝나면 표준 출력에 -1을 쓴다.

// 입력 11 2
// 출력 5

// 경찰의 위치 11 12 14 17 21 26
// 도둑 2 3 6 12 13 26
// 도둑은 경찰을 5초만에 잡을 수 있다.


#include<queue>
#include<iostream>
using namespace std;

void BFS(int police , int stealer)
{
    queue<int> Q;
    Q.push(stealer);
    int _police = police;
    int _time=-1;//단계별 police 추가 거리
    while(!Q.empty())
    {
        unsigned int number = Q.size();
        //_police += _time += 1; //
        _time += 1;
        _police += _time;

        for(unsigned int  i = 0 ;  i < number ; i++ )
        {
            int _stealer = Q.front();
            if(_stealer == _police)
            {
                cout << _time << endl;
                return ;
            }

            Q.pop();

            if(_stealer < 0 || _stealer > 200000 || _police < 0 || _police > 200000)
            {
                continue;
            }

            Q.push(_stealer+1);
            Q.push(_stealer-1);
            Q.push(_stealer*2);
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

