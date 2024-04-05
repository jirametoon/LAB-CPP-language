#include <iostream>
#include <vector>
#define MAX_N 100001
using namespace std;

int main(void) 
{
    int n;
    cin >> n;

    vector<int> start(n), finish(n), weight(n), res;
    for (int i = 0; i < n; i++)
        cin >> start[i] >> finish[i] >> weight[i];

    int dp[MAX_N];
    int maxIdx = 0; 

    dp[0] = weight[0];

    for (int i = 1; i < n; i++) 
	{
        dp[i] = weight[i];

        for (int j = i - 1; j >= 0; j--) 
            if (finish[j] <= start[i])
                if (dp[i] < dp[j] + weight[i]) 
				{
                    dp[i] = dp[j] + weight[i];
                    maxIdx = i;
                    break; 
                }

        dp[i] = max(dp[i], dp[i-1]);
    }

    cout << dp[n-1] << "\n";

    int currIdx = maxIdx;
    while (currIdx >= 0) 
	{
        res.push_back(currIdx);
        int prevIdx = -1;

        for (int j = currIdx - 1; j >= 0; j--) 
            if (finish[j] <= start[currIdx] && dp[currIdx] == dp[j] + weight[currIdx]) 
			{
                prevIdx = j;
                break;
            }

        currIdx = prevIdx;
    }

    cout << res.size() << "\n"; 
    for (int i = res.size() - 1; i >= 0; i--) 
        cout << res[i] + 1 << " ";

    return (0);
}
