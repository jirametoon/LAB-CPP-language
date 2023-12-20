#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	size_t	l, n, m, num = 1, pos = 0, size;
	char	c;
	cin >> l >> n;

	vector<vector<size_t>>	chain(l);
	vector<size_t>			tmp, res;

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
			tmp.clear();
			size = chain[0].size();

			for (size_t i = pos + 1; i < size; i++)
			{
				tmp.insert(tmp.begin(), chain[0].back());
				chain[0].pop_back();
			}
			
			size = chain.size();
			for (size_t i = 1; i < size; i++)
			{
				if (num == chain[i].front())
				{
					for (size_t val : chain[i])
						chain[0].push_back(val);
					chain.erase(chain.begin() + i);
					break ;
				}
				else if (num == chain[i].back())
				{
					reverse(chain[i].begin(), chain[i].end());
					for (size_t val : chain[i])
						chain[0].push_back(val);
					chain.erase(chain.begin() + i);
					break ;
				}
			}

			if (!tmp.empty())
				chain.insert(chain.end(), tmp);
			pos++;
		}

		res.push_back(chain[0][pos]);
	}

	for (size_t val : res)
		cout << val << "\n";
	return (0);
}

/*
4 10
3
4
2
5
B 
F 
C 9 
C 4 
F 
B 
F 
C 3 
F 
C 14
*/