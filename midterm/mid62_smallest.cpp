#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	int n, q, m, k, num, min;
	cin >> n >> q;

	vector<int>	height, answer, min_height;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		height.push_back(num);
		if (!i || min > num)
			min = num;
		min_height.push_back(min);
	}

	while (q--)
	{
		cin >> m >> k;

		if (m == 1)
			answer.push_back(min_height[k - 1]);
		else if (m == 2)
		{
			if (k > height[0])
				answer.push_back(0);
			else
			{
				min = 0;
				for (int i = 0; i < n; i++)
				{
					if (min_height[i] < k)
					{
						min = i;
						break ;
					}
					else if (i == n - 1)
					{
						min = i + 1;
						break ;
					}
				}
				answer.push_back(min);
			}
		}
	}

	for (int val : answer)
		cout << val << "\n";
	return (0);
}