#include <iostream>
#include <vector>
#include <set>
using namespace std;

int	main(void)
{
	size_t	n, q, sum;
	cin >> n >> q;

	vector<size_t>	woods(n), brigde(q);
	set<size_t>		total;
	vector<bool>	check(q, false);

	for (size_t i = 0; i < n; i++)
		cin >> woods[i];
	for (size_t i = 0; i < q; i++)
		cin >> brigde[i];

	for (size_t i = 0; i < n; i++)
	{
		sum = 0;
		for (size_t j = i; j < n; j++)
		{
			sum += woods[j];
			total.insert(sum);
		}
	}

	for (size_t i = 0; i < q; i++)
	{
		auto it = total.find(brigde[i]);

		if (it != total.end())
			check[i] = true;
	}

	for (size_t i = 0; i < q; i++)
	{
		if (check[i])
			cout << "Y";
		else
			cout << "N";
	}
	return (0);
}