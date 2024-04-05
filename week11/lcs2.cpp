#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int lcs(string s, string t, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
        return (0);

    if (dp[m][n] == -1)
    {
        if (s[m - 1] == t[n - 1])
            dp[m][n] = 1 + lcs(s, t, m - 1, n - 1, dp);
        else
            dp[m][n] = max(lcs(s, t, m, n - 1, dp), lcs(s, t, m - 1, n, dp));
    }

    return (dp[m][n]);
}

string getlcs(string s, string t, int m, int n, vector<vector<int>> &dp)
{
    string result;

    while (m > 0 && n > 0)
	{
        if (s[m - 1] == t[n - 1])
		{
            result = s[m - 1] + result;
            m--;
            n--;
        }
		else if (dp[m - 1][n] > dp[m][n - 1])
            m--;
        else
            n--;
    }

    return (result);
}

int	main(void)
{
	string s, t;
	cin >> s >> t;

    int m = s.size();
    int n = t.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

	cout << lcs(s, t, m, n, dp) << "\n" << getlcs(s, t, m, n, dp);
	return (0);
}
