#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<size_t>> get_input(void)
{
	size_t	n, d, c;
	cin >> n;

	vector<vector<size_t>> jobs(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> d >> c;
		jobs[i] = {d, c};
	}

	sort(jobs.begin(), jobs.end());
	return (jobs);
}

size_t	find_pay(vector<vector<size_t>> &jobs)
{
	size_t	dateline, date = 0, currentpay = 0, pay = 0;

	for (auto job : jobs)
	{
		dateline = job[0];
		date += job[1];

		if (date > dateline + 10)
		{
			currentpay = (date - dateline - 10) * 1000;
			if (currentpay > pay)
				pay = currentpay;
		}
	}

	return (pay);
}

int	main(void)
{
	vector<vector<size_t>>	jobs = get_input();

	cout << find_pay(jobs);
	return (0);
}