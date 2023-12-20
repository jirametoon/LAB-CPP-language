#include <iostream>
#include <set>
#include <vector>
using namespace std;

int	main(void)
{
	size_t	n, m, num;
	cin >> n >> m;

	set<size_t>		myset;
	vector<size_t>	res;

	while (n--)
	{
		cin >> num;
		myset.insert(num);
	}


	while (m--)
	{
		cin >> num;

		if (num > *--myset.end())
			res.push_back(*--myset.end());
		else if (num < *myset.begin())
			res.push_back(*myset.begin());
		else if (num == *myset.find(num))
			res.push_back(num);
		else
		{
			auto it1 = myset.upper_bound(num);
			auto it2 = it1--;

			if (*it2 - num >= num - *it1)
				res.push_back(*it1);
			else
				res.push_back(*it2);
		}
	}

	for (size_t val : res)
		cout << val << "\n";

	return (0);
}