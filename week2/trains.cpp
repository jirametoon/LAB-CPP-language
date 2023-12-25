#include <iostream>
#include <map>
#include <list>
using namespace std;

int	main(void)
{
	size_t	n, x, y;
	char	c;
	cin >> n;

	map<size_t, list<size_t>>	train;

	while (n--)
	{
		cin >> c >> x >> y;

		if (c == 'N')
			train[y].push_back(x);
		else if (c == 'M')
		{
			train[y].splice(train[y].end(), train[x]) ;
			train[x].clear();
		}

	}

	for (const auto &key : train)
		for (size_t val : key.second)
			cout << val << "\n";
	
	return (0);
}