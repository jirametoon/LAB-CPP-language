#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	int	n, t, tmp;
	cin >> n >> t;

	vector<int>	passwd(n);

	for (int i = 0; i < n; i++)
		cin >> passwd[i];

	tmp = passwd[0];

	if (t == 2)
	{
		for (int i = 1; i < n; i++)
		{
			if (passwd[i] > 2 * passwd[i - 1])
				passwd[i] -= 2 * passwd[i - 1];
			else
				passwd[i] -= passwd[i - 1];
		}
	}

	if (passwd[0] > n)
		passwd[0] = 1;
	else
		passwd[0] = 0;

	for (int i = 1; i < n; i++)
	{
		if (passwd[i] > tmp)
		{
			tmp = passwd[i];
			passwd[i] = 1;
		}
		else
		{
			tmp = passwd[i];
			passwd[i] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << passwd[i];
		if (i != n - 1)
			cout << "\n";
	}
	return (0);
}