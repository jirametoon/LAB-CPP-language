#include <iostream>
using namespace std;

int	main(void)
{
	int	count, num;
	int res = 0;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> num;
		if (num > 0)
			res += num;
	}

	cout << res;
	return (0);
}