#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	size_t	n, s, t, end = 0, count = 0;
	cin >> n;

	vector<pair<size_t, size_t>>	intsch;
	
	for (size_t i = 0; i < n; i++)
	{
		cin >> s >> t;
		intsch.push_back({t, s});
	}

	sort(intsch.begin(), intsch.end());

	for (size_t i = 0; i < n; i++)
	{
		if (end <= intsch[i].second)
		{
			end = intsch[i].first;
			count++;
		}

	}

	cout << count;
	return (0);
}