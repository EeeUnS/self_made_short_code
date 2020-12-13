#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

typedef complex<double> base;



constexpr double PI = 3.14159265358979323846;

void fft(vector <base>& inOutF, bool invert)
{
	const int n = inOutF.size();
	for (int i = 1, j = 0; i < n; i++)
	{
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
		{
			j -= bit;
		}
		j += bit;
		if (i < j)
		{
			swap(inOutF[i], inOutF[j]);
		}
	}
	for (int len = 2; len <= n; len <<= 1)
	{
		double ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len)
		{
			base w(1);
			for (int j = 0; j < len / 2; j++)
			{
				base u = inOutF[i + j];
				base v = inOutF[i + j + len / 2] * w;
				inOutF[i + j] = u + v;
				inOutF[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
	{
		for (int i = 0; i < n; i++)
		{
			inOutF[i] /= n;
		}
	}
}

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res)
{
	vector <base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < a.size() + b.size())
	{
		n <<= 1;
	}
	fa.resize(n);
	fb.resize(n);
	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; i++)
	{
		fa[i] *= fb[i];
	}
	fft(fa, true);
	res.resize(n);
	for (int i = 0; i < n; i++)
	{
		res[i] = round(fa[i].real());
	}
}