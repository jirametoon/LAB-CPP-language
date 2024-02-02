#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	size_t	n, m, count = 0;
	cin >> n >> m;

	vector<size_t>	boat(n), week(m);

	for (size_t i = 0; i < n; i++)
		cin >> boat[i];
	for (size_t i = 0; i < m; i++)
		cin >> week[i];
	
	sort(boat.begin(), boat.end());

	for (size_t i = 0; i < m; i++)
	{
		auto it = lower_bound(boat.begin(), boat.end(), week[i]);

		if (it == boat.end())
			break ;
		count++;
		boat.erase(it);
	}

	cout << count << "\n";
	return (0);
}
