#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<vector<int>> pairs(100005, vector<int>(2));
    vector<vector<int>> result(100005, vector<int>(2));

    int numTests, maxLength;
    
    cin >> numTests;
    
    while (numTests--)
    {
        string separator = "";
        cout << separator;
        separator = "\n";
        
        cin >> maxLength;
        
        int numPairs = 0;
        while (cin >> pairs[numPairs][0] >> pairs[numPairs][1], pairs[numPairs][0] || pairs[numPairs][1])
        {
            if (pairs[numPairs][1] > 0 && pairs[numPairs][0] < maxLength)
                ++numPairs;
        }
        
        sort(pairs.begin(), pairs.begin() + numPairs);
        
        pairs[numPairs][0] = maxLength + 1;
        
        int count = 0;
        int currentX = 0;
        int currentPair = 0;
        
        while (currentX < maxLength && currentPair < numPairs)
        {
            result[count][1] = 0;
            for (currentPair = 0; pairs[currentPair][0] <= currentX; ++currentPair)
                if (pairs[currentPair][1] > result[count][1])
                {
                    result[count][0] = pairs[currentPair][0];
                    result[count][1] = pairs[currentPair][1];
                }
            
            if (result[count][1] == currentX)
                break;

            currentX = result[count][1];
            ++count;
        }
        
        if (currentX >= maxLength)
        {
            cout << count << '\n';
            
            for (int i = 0; i < count; ++i)
            {
                cout << result[i][0] << ' ' << result[i][1] << '\n';
            }
        }
        else
            cout << "0\n";
    }
    return (0);
}
