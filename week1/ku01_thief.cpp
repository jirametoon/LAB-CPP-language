#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	int n, k, t, p, res = 1;
	cin >> n >> k >> t;

	vector<int>	ppl(n, 0);
	t -= 1;
	ppl[k] = 1;
	p = k;

	while (!ppl[0] && !ppl[t])
	{
		ppl[(p + k) % n] = 1;
		ppl[p] = 0;
		p = (p + k) % n;
		res++;
	}

	if (ppl[t])
		cout << res + 1;
	else
		cout << res;
	return (0);
}