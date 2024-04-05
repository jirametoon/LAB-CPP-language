#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int bottomUpdp(vector<vector<int>> &dp, vector<int> &C, int end)
{
	for (int i = 0; i < end; i++)
		dp[i][i + 1] = 0;

	for (int l = 2; l <= end; l++)
		for (int i = 0; i <= (end - l); i++)
		{
			int j = i + l;
			dp[i][j] = INT_MAX;

			for (int k = i + 1; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (C[j] - C[i]));
		}

	return (dp[0][end]);
}

int main(void)
{
    int n, length;
	vector<vector<int>> dp(52, vector<int>(52, 0));
    vector<int> C(52);

    while (true)
    {
        cin >> length;

        if (length == 0)
            break;

        cin >> n;
        C[0] = 0;

        for (int i = 1; i <= n; i++)
            cin >> C[i];

        C[n + 1] = length;

        cout << "The minimum cutting is " << bottomUpdp(dp, C, n + 1) << ".\n";
    }
    return (0);
}
