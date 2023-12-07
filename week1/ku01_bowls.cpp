#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int	main(void)
{
	int count, num;
	int	cnum[300];

	cin >> count;
	memset(cnum, 0, sizeof(cnum));
	for (int i = 0; i < count; i++)
	{
		cin >> num;
		cnum[num - 1]++;
	}

	cout << *max_element(cnum, cnum + 300);
	return (0);
}