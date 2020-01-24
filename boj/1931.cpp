#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct beginend {
	unsigned int begin;
	unsigned int end;
};

vector<beginend> a;

bool comp(const beginend &x,const beginend& y) {
	if (x.end !=y.end)
	{
		return x.end < y.end;
	}
	else
	{
		return  x.begin < y.begin;
	}

}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, count = 0;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i].begin >> a[i].end;
	}

	sort(a.begin(), a.end(), comp);
	//stable_sort(a.begin(), a.end(), comp);
	/*for (auto i : a)
	{
		cout << i.begin << ' ' << i.end << endl;
	}*/

	unsigned int time = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].begin >= time) {
			time = a[i].end;
			count++;
		}
	}
	cout << count ;
	return 0;
}
