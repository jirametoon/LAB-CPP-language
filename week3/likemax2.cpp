#include <iostream>
#include <vector>
#include <map>
using namespace std;

int	main(void)
{
	size_t n, a, b, max_key = 0, max_value = 0;
	cin >> n;

	map<size_t, size_t>	status;
	vector<size_t>	res;

	while (n--)
	{
		cin >> a >> b;

		if (a == 1)
			status[b]++;
		else if (a == 0)
			status[b]--;

		res.push_back(max_key);
	}


	for (size_t val : res)
		cout << val << "\n";
	return (0);
}