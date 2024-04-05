#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int testCases, caseNumber = 1;
    cin >> testCases;

    while (testCases--)
	{
        int companies;
        long long maxShares, totalProfit = 0, bonus;
        cin >> companies >> maxShares;

        vector<long long> shares(companies);

        for (int i = 0; i < companies; ++i)
		{
            cin >> shares[i];
            shares[i] *= -1;
        }

        for (int i = 0; i < companies; ++i)
		{
            cin >> bonus;
            shares[i] += bonus;
        }

        sort(shares.begin(), shares.end());

        for (int share : shares) 
		{
            if (share < 0 && maxShares)
                maxShares--;
            else
                totalProfit += share;
        }

        cout << "Case " << caseNumber++ << ": ";
        if (totalProfit > 0)
            cout << totalProfit << endl;
        else
            cout << "No Profit" << endl;
    }
	
    return (0);
}
