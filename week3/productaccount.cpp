#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	size_t	m, a, b, x;
	cin >> m;

	map<size_t, size_t>	product;
	vector<size_t>		res;

	while (m--)
	{
		cin >> x;

		if (x == 1)
		{
			cin >> a >> b;
			product[a] += b;
		}
		else if (x == 2)
		{
			cin >> a;
			res.push_back(product[a]);
		}
		else if (x == 3)
		{
			cin >> a >> b;

			if (b > product[a])
			{
				res.push_back(product[a]);
				product[a] = 0;
			}
			else
			{
				product[a] -= b;
				res.push_back(b);
			}
		}
	}

	for (size_t val : res)
		cout << val << "\n";
	return (0);
}