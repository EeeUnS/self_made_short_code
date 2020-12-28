
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> arr;

ffor(i, n + 1)
	{
		ffor(j, n + 1)
		{
			arr[i][j] = INF;
		}
	}

	
void FloydWashal()
{
    const int n = arr.size()-1;
    for(int k = 1 ; k <= n ; k++)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= n; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
}



constexpr int INF = 0x3FFF'FFFF;

typedef std::vector<vector<int>> Graph;
constexpr int vertexNum = 1002;
int Distance[vertexNum+2];
int W[vertexNum+2][vertexNum+2];
//int predecessor_subgraph[vertexNum + 2];

void DIJKSTRA(const Graph& G,
	int W[][vertexNum+2],
	int Distance[], int s)
{
	fill(Distance, Distance + G.size() + 1, INF);
	Distance[s] = 0;

	std::priority_queue<std::pair<int, int>, 
		std::vector<std::pair<int, int>>, 
		std::greater<std::pair<int, int>> > PQ; //정점의 거리, 정점

	PQ.push({ Distance[s], s });

	while (!PQ.empty())
	{
		int u = PQ.top().second;
		PQ.pop();
		for (std::size_t i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (Distance[v] > Distance[u] + W[u][v])
			{
				Distance[v] = Distance[u] + W[u][v];
				//predecessor_subgraph[v] = u;
				PQ.push(std::make_pair(Distance[v], v));
			}
		}
	}
}

main..
	ffor(i, n + 1)
	{
		ffor(j, n + 1)
		{
			W[i][j] = INF;
		}
	}