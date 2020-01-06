#include<cstdio>
#include <list>

using namespace std;

int main()
{
    int n = 0 ;
    list<int> listSet;
    char a;
    while((a = getchar()) != '\n')
    {
        listSet.push_back(a);
    }
    scanf("%d", &n) ;
    auto itr = listSet.end();
    getchar();
    for(int i = 0 ; i <  n ; i++)
    {
        char instruction = getchar() ;
        char alp = 0 ;
        switch (instruction)
        {
        case 'P':
            getchar();
            alp = getchar();
            listSet.insert(itr, alp);
            break;
        case 'L':
            if( itr != listSet.begin())
            {
                --itr;
            }
            break;
        case 'D':
            if( itr != listSet.end())
            {
                ++itr;
            }
            break;
        case 'B':
            if( itr != listSet.begin())
            {
                itr = listSet.erase(--itr);
            }
            break;
        default:
            //cout << "error" << endl;
            break;
        }
        getchar(); // \n
    }
    for(char i : listSet)
    {
        putchar(i) ;
    }


    return 0;
}
