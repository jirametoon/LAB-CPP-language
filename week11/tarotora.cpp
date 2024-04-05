#include <iostream>
#include <vector>
#include <algorithm>
#define	maximum 1000000000
using namespace std;

int main(void)
{
    int c, n, k; 
	cin >> c;

	vector<vector<int>>	dp(100001, vector<int>(209, maximum));
	vector<int>			ans(c, maximum);

    for (int x = 0; x < c; x++)
	{
        cin >> n >> k;
        int start = 101 - k, end = 101 + k;
		
        dp[0][101] = 0;
        for(int i = 1; i <= n; i++)
		{
            int left, right; 
			cin >> left >> right;

            for(int j = start; j <= end; j++)
                dp[i][j] = min(dp[i - 1][j - 1] + left, dp[i - 1][j + 1] + right);
        }

        for(int i = start; i <= end; i++)
            ans[x] = min(ans[x], dp[n][i]);

    }

	for (int val : ans)
		cout << val << "\n";
    return (0);
}