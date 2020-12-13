

typedef ll ll;

ll gcd(ll a,ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}



ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b ;
}



ll extended_Euclid_for_multiple_inverse( ll a, ll mod_n)
{
	if (gcd(a, mod_n) != 1)
		return -1;
	 ll r1 = a, r2 = mod_n;
	ll t1 = 0, t2 = 1;
	 ll u, r, t;
	while (r2 > 0)
	{
		u = r1 / r2;

		r = r1 % r2;
		r1 = r2; r2 = r;

		t = t1 - u * t2;
		t1 = t2; t2 = t;
	}
	if (t1 < 0)
		t1 += mod_n;

	return t1;  //e
}



ll exponent_Mod( ll base,  ll exponent,  ll mod_N)
//encryption and decryption
{
	if (base == 0)
		return 0;
	if (exponent == 0)
		return 1;
	ll y;

	if (exponent % 2 == 0) {
		y = exponent_Mod(base, exponent / 2, mod_N);
		y = (y * y) % mod_N;
	}
	else {
		y = base % mod_N;
		y = (y * exponent_Mod(base, exponent - 1, mod_N) % mod_N) % mod_N;
	}
	return ((y + mod_N) % mod_N);
}

ll factorialMod(ll n, ll mod)
{
	if (n == 0)
	{
		return 1;
	}
	ll tmp = 1;
	for (int i = 2; i <= n; i++)
	{
		tmp *= i;
		tmp %=mod;
	}
	return tmp;
}

