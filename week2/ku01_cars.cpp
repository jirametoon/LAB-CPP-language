#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<size_t>> get_input(void)
{
	size_t	n, p, v;
	cin >> n;

	vector<vector<size_t>> cars(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> p >> v;
		cars[i] = {p, v};
	}

	sort(cars.begin(), cars.end());
	return (cars);
}

size_t find_unsell_car(vector<vector<size_t>> &cars)
{
	size_t max = 0, res = 0;

	for (const vector<size_t> &car : cars)
	{
		if (max < car[1])
			max = car[1];	
		else
			res++;
	}

	return (res);
}

int	main(void)
{
	vector<vector<size_t>>	cars = get_input();

	cout << find_unsell_car(cars);
	return (0);
}