#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	size_t	n, s, max_key = 0, max_value = 0;
	cin >> n;

	map<size_t, size_t>	like;
	vector<size_t>		res;

	for (size_t i = 0; i < n; i++)
	{
		cin >> s;
		
		like[s]++;
		if (max_value <= like[s])
		{
			max_value = like[s];
			max_key = s;
		}

		res.push_back(max_key);
    }
		
	for (size_t val : res)
		cout << val << "\n";
	return (0);
}