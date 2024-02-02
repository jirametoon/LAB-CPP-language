#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	size_t	n, d, c, dl, time, date = 0, currentpay = 0, pay = 0;
	cin >> n;

	vector<pair<size_t, size_t>>	jobs;

	for (size_t i = 0; i < n; i++)
	{
		cin >> d >> c;

		jobs.push_back({d, c});
	}

	sort(jobs.begin(), jobs.end());

	for (size_t i = 0; i < n; i++)
	{
		dl = jobs[i].first;
		time = jobs[i].second;
		date += time;

		if (date > dl + 10)
		{
			currentpay = (date - dl - 10) * 1000;
			if (currentpay > pay)
				pay = currentpay;
		}
	}

	cout << pay;
	return (0);
}