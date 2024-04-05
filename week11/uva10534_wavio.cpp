#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void calculateLIS(const vector<size_t> &sequence, vector<size_t> &LIS)
{
    vector<size_t> length(sequence.size());
    size_t lisCount = 0;

    for (size_t i = 0; i < sequence.size(); i++)
    {
        size_t pos = lower_bound(length.begin(), length.begin() + lisCount, sequence[i]) - length.begin();
        length[pos] = sequence[i];
        if (pos == lisCount)
            ++lisCount;
        LIS[i] = pos + 1;
    }
}

int main(void)
{  
    size_t N;

    while (cin >> N)
    {
        vector<size_t> sequence(N);

        for (size_t i = 0; i < N; ++i)
            cin >> sequence[i];
        
        vector<size_t> LIS(N), LDS(N);

        calculateLIS(sequence, LIS);
        reverse(sequence.begin(), sequence.end());
        calculateLIS(sequence, LDS);
        reverse(LDS.begin(), LDS.end());

        size_t maxSubsequenceLength = 0;

        for (size_t i = 0; i < LIS.size(); ++i)
            maxSubsequenceLength = max(maxSubsequenceLength, 2 * min(LIS[i], LDS[i]) - 1);

        cout << maxSubsequenceLength << "\n";
    }
    return 0;
}
