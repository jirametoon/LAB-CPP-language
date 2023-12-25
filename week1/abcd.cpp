#include <iostream>
using namespace std;

int	main(void)
{
	int	num;
	int	res = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> num;
		res += num;
	}

	cout << res;
	return (0);
}