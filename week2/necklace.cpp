#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	size_t	n, x, y, Y, m = 0;
	cin >> n;

	vector<vector<size_t>>	necklace(n);
	vector<size_t>			order(n), position(n);

	for (size_t i = 0; i < n; i++)
	{
		necklace[i].push_back(i + 1);
		order[i] = 0;
		position[i] = i + 1;
	}

	while (--n)
	{
		cin >> x >> y;

		Y = y;
		if (necklace[y - 1].empty())
			y = position[y - 1];

		while (!necklace[x - 1].empty())
		{
			necklace[y - 1].insert(necklace[y - 1].begin() + order[Y - 1] + 1, necklace[x - 1].back());
			necklace[x - 1].pop_back();
		}

		for (size_t i = 0; i < necklace[y - 1].size(); i++)
		{
			order[necklace[y - 1][i] - 1] = i;
			position[necklace[y - 1][i] - 1] = y;
		}
	}

	while (necklace[m].empty())
		m++;
	
	cout << necklace[m][0];
	for (size_t i = 1; i < necklace[m].size(); i++)
		cout << " " << necklace[m][i];

	return (0);
}