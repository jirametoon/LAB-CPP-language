#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
    long n, k, res = 0;
    cin >> n >> k;

    vector<long>	runner(n);

    for (long i = 0; i < n; i++)
		cin >> runner[i];

    sort(runner.begin(), runner.end());

	for (long j = 1; j < n; j++)
	{
		if (runner[j] * (k - 1) >= runner[0] * (k))
			break ;
		res++;
	}
	
    cout << res+1;
    return (0);
}
