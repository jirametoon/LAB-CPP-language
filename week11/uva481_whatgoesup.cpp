#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printLongestIncreasingSubsequence(const vector<int> &sequence, const vector<int> &prevIndices, int currentPos)
{
    if (currentPos == -1)
        return ;

    printLongestIncreasingSubsequence(sequence, prevIndices, prevIndices[currentPos]);
    cout << sequence[currentPos] << "\n";
}

int main(void)
{  
    int num;
    vector<int> sequence;

    while (cin >> num)
        sequence.push_back(num);

    vector<int> minEndValue(sequence.size());
    vector<int> minEndValueIndex(sequence.size());
    vector<int> previousIndices(sequence.size());

    int endOfLIS = 0, lisLength = 0;

    for (int i = 0; i < sequence.size(); i++)
    {
        size_t pos = lower_bound(minEndValue.begin(), minEndValue.begin() + lisLength, sequence[i]) - minEndValue.begin();
        minEndValue[pos] = sequence[i];
        minEndValueIndex[pos] = i;
        previousIndices[i] = pos ? minEndValueIndex[pos - 1] : -1;
        if (pos == lisLength)
        {
            ++lisLength;
            endOfLIS = i;
        }
    }
    
    cout << lisLength << "\n-\n";
    printLongestIncreasingSubsequence(sequence, previousIndices, endOfLIS);

    return (0);
}
