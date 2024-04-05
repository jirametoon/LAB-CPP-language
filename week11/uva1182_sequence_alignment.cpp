#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void reverseString(char s[], int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
        swap(s[i], s[j]);
}

int dp[64][64][2][2];

int main(void)
{
    int testcase;
    char s1[64], s2[64];
    cin >> testcase;

    while (getchar() != '\n');

    while (testcase--) 
	{
        cin.getline(s1, 64);
        cin.getline(s2, 64);
        int n1 = strlen(s1), n2 = strlen(s2);
        reverseString(s1, n1);
        reverseString(s2, n2);
        
        memset(dp, -0x3f, sizeof(dp));
        dp[0][0][0][1] = 0;
        dp[0][0][1][1] = 0;
        int res = -0x3f3f3f3f;

        for (int i = 0; i <= n1; i++)
            for (int j = 0; j <= n2; j++)
			{
                int v = max({dp[i][j][0][0], dp[i][j][0][1], dp[i][j][1][0], dp[i][j][1][1]});

                dp[i + 1][j + 1][0][1] = dp[i + 1][j + 1][1][1] = max(dp[i + 1][j + 1][0][1], v);

                if (s1[i] == s2[j])
				{
                    dp[i + 1][j + 1][0][1] = max(dp[i + 1][j + 1][0][1], v + 2);
                    dp[i + 1][j + 1][1][1] = max(dp[i + 1][j + 1][1][1], v + 2);
                }

                dp[i + 1][j][0][0] = max({dp[i + 1][j][0][0], dp[i][j][0][0], dp[i][j][1][0] - 1, dp[i][j][0][1] - 1, dp[i][j][1][1] - 1});
                dp[i][j + 1][1][0] = max({dp[i][j + 1][1][0], dp[i][j][1][0], dp[i][j][0][0] - 1, dp[i][j][0][1] - 1, dp[i][j][1][1] - 1});

                if (j == n2 || i == n1)
                    res = max(res, max({dp[i][j][0][0], dp[i][j][0][1], dp[i][j][1][0], dp[i][j][1][1]}));
            }

        cout << res << "\n";
    }
    return (0);
}
