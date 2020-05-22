
//정수론 라이브러리 1.
//모듈러 곱셈역 V
//컴비네이션
//퍼뮤테이션
//지수승 / mod v
//gcd v
//lcm v
//
unsigned long long int gcd(const unsigned long long int a, const unsigned long long int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

unsigned long long int lcm(const unsigned long long int a, const unsigned long long int b)
{
	return (a / gcd(a, b)) * b ;
}

unsigned long long int extended_Euclid_for_multiple_inverse(const unsigned long long int a, const unsigned  long long int mod_n)
{
	if (gcd(a, mod_n) != 1)
		return -1;
	unsigned long long r1 = a, r2 = mod_n;
	long long t1 = 0, t2 = 1;
	unsigned long long u, r, t;
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

unsigned long long int Fibonacci(const unsigned long long int n, const unsigned long long int k) //made fuction stack
{
	if (k == n) return 1;
	else if (k == 1) return n;
	else return (Fibonacci(n - 1, k - 1) + Fibonacci(n - 1, k)) % 1000000007;
}

unsigned long long int exponent_Mod(const unsigned long long int base, const unsigned long long int exponent, const unsigned long long int mod_N)
//encryption and decryption
{
	if (base == 0)
		return 0;
	if (exponent == 0)
		return 1;
	unsigned long long int y;

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


unsigned long long int exponent(const unsigned long long int base, const unsigned long long int power)
{
	if (base == 0)
		return 0;
	if (exponent == 0)
		return 1;
	unsigned long long int y;

	if (power % 2 == 0) {
		y = exponent(base, power / 2 );
		y = (y * y) ;
	}
	else {
		y = base;
		y = y * exponent(base, power - 1);
	}
	return y ;
}


unsigned long long int factorialMod(unsigned long long int n, unsigned long long int mod)
{
	if (n == 0)
	{
		return 1;
	}
	unsigned long long int tmp = 1;
	for (int i = 2; i <= n; i++)
	{
		tmp *= i;
		tmp %=mod;
	}
	return tmp;
}

