#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	size_t	n, p, v, max = 0, res = 0;
	cin >> n;

	vector<vector<size_t>> cars(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> p >> v;
		cars[i] = {p, v};
	}

	sort(cars.begin(), cars.end(), [](const vector<size_t> &vec1, const vector<size_t> &vec2) -> bool 
	{
		return (vec1[0] < vec2[0]);
	});

	for (const vector<size_t> &car : cars)
	{
		if (max < car[1])
			max = car[1];
		else
			res++;
	}

	cout << res;
	return (0);
}