#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	size_t	n, num;
	cin >> n;

	vector<size_t>	diff, price(n);

	for (size_t i = 0; i < n; i++)
		cin >> price[i];

	for (size_t i = 0; i < n; i++)
	{
		num = 0;
		for (size_t j = 0; j < price.size(); j++)
		{
			num += price[j];
			if (find(diff.begin(), diff.end(), num) == diff.end())
				diff.push_back(num);
		}
		price.erase(price.begin());
	}

	cout << diff.size();
	return (0);
}