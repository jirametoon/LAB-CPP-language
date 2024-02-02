#include <iostream>
#include <cmath>
using namespace std;

bool	isPrime(size_t n)
{
	if (n <= 1)
		return (false);
	if (n == 2)
		return (true);
	if (!(n % 2))
		return (false);
	for (size_t i = 3; i * i <= n; i++)
		if (!(n % i))
			return (false);
	return (true);
}

int	main(void)
{
	int l, r, a = -1, b = -2, count = 0;
	cin >> l >> r;

	for (int i = l; i <= r; i++)
	{
		if (isPrime(i))
		{
			if (a > b)
				b = i;
			else
				a = i;
			if (abs(a - b) == 2)
				count++;
		}

	}

	cout << count;
	return (0);
}