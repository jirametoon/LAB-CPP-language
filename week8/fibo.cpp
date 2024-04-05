#include <iostream>
using namespace std;

size_t	fibo(int n)
{
	size_t	f1 = 0, f2 = 1, res;
	if (!n)
		return (0);
	else if (n == 1)
		return (1);
	
	while (n-- > 1)
	{
		res = ((f2 % 199933) + (f1 % 199933)) % 199933;
		f1 = f2;
		f2 = res;
	}
	return (res);
}

int	main(void)
{
	int	n;
	cin >> n;

	cout << fibo(n) % 199933;
	return (0);
}