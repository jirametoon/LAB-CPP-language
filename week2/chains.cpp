#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void kuy1(const std::vector<size_t>& vector) {
    std::cout << "[ ";
    for (size_t element : vector) {
        std::cout << element << " ";
    }
    std::cout << "]\n";
}

void kuy2(const std::vector<std::vector<size_t>>& matrix) {
    for (const auto& row : matrix) {
        kuy1(row);
    }
}

int	main(void)
{
	size_t	l, n, m, num = 1, pos = 0, size;
	char	c;
	cin >> l >> n;

	vector<vector<size_t>>	chain(l);
	vector<size_t>		tmp, res;

	for (size_t i = 0; i < l; i++)
	{
		cin >> m;

		for (size_t j = 0; j < m; j++)
			chain[i].push_back(num++);
	}

	while (n--)
	{
		cin >> c;

		if (c == 'F')
		{
			if (pos < chain[0].size() - 1)
				pos++;
		}
		else if (c == 'B')
		{
			if (pos)
				pos--;
		}
		else if (c == 'C')
		{
			cin >> num;

			for (size_t i = 1; i < l; i++)
			{
				if (num == chain[i].back())
					sort(chain[i].rbegin(), chain[i].rend());
				if (num == chain[i].front())
				{
					size = chain[i].size();
					chain[0].insert(chain[0].begin() + pos + 1, chain[i].begin(), chain[i].end());
					chain[i].clear();
					chain[i].insert(chain[i].begin(), chain[0].begin() + pos + 1 + size, chain[0].end());
					chain[0].erase(chain[0].begin() + pos + 1 + size, chain[0].end());
				}
			}
			pos++;
		}
		res.push_back(chain[0][pos]);
	}

	for (size_t val : res)
		cout << val << "\n";
	return (0);
}
