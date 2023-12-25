#include <iostream>
using namespace std;

int	getScore(int num)
{
	if (num <= 4)
		return (5);
	else if (num <= 16)
		return (4);
	else if (num <= 36)
		return (3);
	else if (num <= 64)
		return (2);
	else if (num <= 100)
		return (1);
	return (0);
}

int	main(void)
{
	int count, a, b;
	int res = 0;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> a >> b;
		res += getScore(a*a + b*b);
	}

	cout << res;
	return (0);
}