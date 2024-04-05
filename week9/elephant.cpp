#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int count_bananas(size_t i, const vector<int> &bananas, vector<int> &dp)
{
    if (i < 2 || i >= bananas.size())
        return (0);

    if (dp[i] != -1)
        return (dp[i]);

    int first = bananas[i] + count_bananas(i - 3, bananas, dp);
    int second = count_bananas(i - 1, bananas, dp);
    int third = bananas[i] + count_bananas(i - 4, bananas, dp);
    
    return (max(first, max(second, third)));
}

int maximum(const vector<int>& bananas)
{
    size_t size = bananas.size();
    vector<int> dp(size, -1);

    int res = 0;
    for (size_t i = 0; i < size; i++)
        res = max(res, count_bananas(i, bananas, dp));

    return (res);
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> bananas(n);
    
    for (int i = 0; i < n; i++)
        cin >> bananas[i];

    cout << maximum(bananas);
    return 0;
}
