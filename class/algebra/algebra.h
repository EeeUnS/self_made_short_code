

long long gcd(long long a,long long b)
{
	if (b == 0)
		return a;
	else
		gcd(b, a%b);
}

long long extended_Euclid_for_multiple_inverse(long long n,long long a)
{
	if (gcd(a, n) != 1)
		return -1;
	long long r1 = a, r2 = n;
	long long t1 = 0, t2 = 1;
	long long u , r, t;
	while (r2>0)
	{
		u = r1 / r2;

		r = r1%r2;
		r1 = r2; r2 = r;

		t = t1 - u * t2;
		t1 = t2; t2 = t;
	}
	if (t1 < 0)
		t1 += a;

	return t1;  //e
}

long long f(long long n,long long k)
{
    if (k == n) return 1;
    else if (k == 1) return n;
    else return (f(n - 1, k - 1) + f(n - 1, k))%1000000007;
}
