#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll table[30][30];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int n = 0; n < 30; n++)
    {
        table[n][0] = 1;
        table[n][n] = 1;
        for (int r = 1; r <= (n / 2); r++)
        {
            table[n][n - r] = table[n][r] = table[n - 1][r - 1] + table[n - 1][r];
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n;
        int r;
        cin >> r >> n;
        cout << table[n][r] << '\n';
    }

    return 0;
}
