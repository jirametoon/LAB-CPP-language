#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	int	n, count = 0, current = -1, step;
	cin >> n;

	vector<int>		stairs(n), must(n);

	for (int i = 0; i < n; i++)
		cin >> stairs[i];
	for (int i = 0; i < n; i++)
		cin >> must[i];

	while (current < n)
	{
		int	min = 1;

		for (int i = 1; i < 5; i++)
		{
			step = i;
			if (must[current + step] || stairs[current + step] > 0 || current + step >= n)
				break ;
			else if (min > 0 || min <= stairs[current + step])
				min = stairs[current + step];
		}

		current += step;
		if (current < n)
			count += stairs[current];
	}

	cout << count;
	return (0);
}