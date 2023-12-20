#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	size_t	n, x, y;
	char	c;
	cin >> n;

	vector<vector<size_t>>	train(n);

	while (n--)
	{
		cin >> c >> x >> y;

		if (c == 'N')
			train[y - 1].push_back(x);
		else if (c == 'M')
		{
			while (!train[x - 1].empty())
			{
				train[y - 1].push_back(train[x - 1].front());
				train[x - 1].erase(train[x - 1].begin());
			}
		}
	}

	for (size_t i = 0; i < train.size(); i++)
		for (size_t val : train[i])
			cout << val << "\n";
	
	return (0);
}