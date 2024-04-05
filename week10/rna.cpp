#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 205;
int n, dp[MAX_N][MAX_N];

bool isPair(char a, char b)
{
	if ((a == 'A' && b == 'U') || (a == 'U' && b == 'A') || (a == 'C' && b == 'G') || (a == 'G' && b == 'C'))
		return (true);
    return (false);
}

int countPairs(int start, int end, string &sequence)
{
    if (start >= end) 
        return (0);

    if (dp[start][end] != -1) 
        return (dp[start][end]);

    int ans = countPairs(start + 1, end, sequence);
    
    for (int mid = start + 4; mid <= end; mid++)
        if (isPair(sequence[start], sequence[mid]))
            ans = max(ans, 1 + countPairs(start + 1, mid - 1, sequence) + countPairs(mid + 1, end, sequence));


    return (ans);
}

int main(void)
{
    string sequence;
    cin >> sequence;

    n = sequence.size();
    memset(dp, -1, sizeof(dp));
    cout << countPairs(0, n - 1, sequence) << "\n";
    return (0);
}
