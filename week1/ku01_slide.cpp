#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	int n, res = 0;
	cin >> n;

	vector<int>	png(n);
	for (int i = 0; i < n; i++)
		cin >> png[i];

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (png[i] < png[j])
				res++;

	cout << res;
	return (0);
}