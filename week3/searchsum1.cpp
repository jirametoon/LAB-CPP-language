#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	size_t	n, k, tmp, total_price = 0, res, money;
	cin >> n >> k;

	vector<size_t>	price(n), answer(k);

	for (size_t i = 0; i < n; i++)
	{
		cin >> tmp;
		total_price += tmp;
		price[i] = total_price;
	}

	for (size_t i = 0; i < k; i++)
	{
		cin >> money;
		res = upper_bound(price.begin(), price.end(), money) - price.begin();
		answer[i] = res;
	}

	for (size_t val : answer)
		cout << val << "\n";
	return (0);
}