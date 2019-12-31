#include <iostream>
#include <vector>

using namespace std;

/*
입력의 첫 줄에는 테스트 케이스의 수 C (C <= 50) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 학생의 수 n (2 <= n <= 10) 과 친구 쌍의 수 m (0 <= m <= n*(n-1)/2) 이 주어집니다. 그 다음 줄에 m 개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어집니다. 번호는 모두 0 부터 n-1 사이의 정수이고, 같은 쌍은 입력에 두 번 주어지지 않습니다. 학생들의 수는 짝수입니다.
*/

vector<vector<int>> set;
vector<bool> visit;

int n, m;

int fun()
{
    int visiting = -1;
    for(int i = 0 ; i < n ;++i)
    {
        if(!visit[i])
        {
            visiting = i;
            break;
        }
    }
    if(visiting < 0)
       { return 1;
       }

    int answer = 0;
    const int size = set[visiting].size();
    for (int k = 0;  k < size; ++k)
    {
        if (!visit[set[visiting][k]])
        {
            visit[visiting] = visit[set[visiting][k]] = true;
            answer += fun();
            visit[visiting] = visit[set[visiting][k]] = false;
        }
    }

    return answer;
}

int main()
{
    int c = 0;
    cin >> c;
    //m이 없는경우 생각하기

    for (int j = 0; j < c; ++j)
    {
        set.resize(10);
        visit.resize(10);
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            if (a > b)
            {
                swap(a, b);
            }
            set[a].push_back(b);
        }

        cout << fun() << '\n';
        set.clear();
        visit.clear();
    }

    return 0;
}

/*
3
4 6
0 1 1 2 2 3 3 0 0 2 1 3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
2 1
0 1
*/
