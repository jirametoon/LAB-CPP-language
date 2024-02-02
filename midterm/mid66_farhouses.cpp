#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	size_t	n, k, l, max = 0;
	cin >> n >> k >> l;

	vector<size_t>	house(n);

	for (size_t i = 0; i < n; i++)
		cin >> house[i];

	sort(house.begin(), house.end());

	for (size_t	i = 0; i < n - k - l; i++)
		if (max < house[i + k + l] - house[i])
			max = house[i + k + l] - house[i];

	cout << max << "\n";
	return (0);
}