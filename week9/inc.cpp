#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	n, size;
vector<int>	seq, res;

void	read_input()
{
	cin >> n;

	int	num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		seq.push_back(num);
	}
}

vector<int> lis(vector<int> &seq, int n)
{
    vector<int>	dp(n, 1);

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (seq[i] > seq[j])
                dp[i] = max(dp[i], dp[j] + 1);

    int max_length = *max_element(dp.begin(), dp.end());

    vector<int>	lis;
    int curr_length = max_length;
    for (int i = n - 1; i >= 0; i--)
        if (dp[i] == curr_length)
		{
            lis.push_back(seq[i]);
            curr_length--;
        }

    reverse(lis.begin(), lis.end());
    return (lis);
}

void	print_output(vector<int> &res, int size)
{
	cout << size << "\n";

	for (int i = 0; i < size; i++)
	{
		cout << res[i];
		if (i == size - 1)
			cout << "\n";
		else
			cout << " ";
	}
}

int	main(void)
{
	read_input();

	res = lis(seq, n);

	print_output(res, res.size());
	return (0);
}