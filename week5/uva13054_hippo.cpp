#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{   
    int numCases, caseNum = 1;
    cin >> numCases;
    
    while(numCases--)
	{
        int numHeights, maxHeight, costAscending, costDescending;
        cin >> numHeights >> maxHeight >> costAscending >> costDescending;
        
        vector<int> heights(numHeights);

        for (int i = 0; i < numHeights; ++i) 
			cin >> heights[i];
        
        sort(heights.begin(), heights.end());
        
        int totalCost = 0;
        if(costAscending * 2 <= costDescending)
            totalCost = numHeights * costAscending;
        else
		{
            int i = 0, j = numHeights - 1;
            while (i < j)
			{
                if(heights[i] + heights[j] < maxHeight)
				{
                    totalCost += costDescending;
					i++;
					j--;
				}
                else
				{
                    totalCost += costAscending;
					j--;
				}
            }
            if(i == j) 
				totalCost += costAscending;
        }
        cout << "Case " << caseNum++ << ": " << totalCost << "\n";
    }
    return (0);
}
