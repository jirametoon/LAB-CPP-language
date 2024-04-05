#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int numWorkers, regularHours, ratePerHour, i, overtime, totalPay;
    vector<int> morningHours(110), eveningHours(110);
    
    while (cin >> numWorkers >> regularHours >> ratePerHour)
	{
        if (numWorkers == 0 && regularHours == 0 && ratePerHour == 0) 
			break ;

        overtime = 0;
        totalPay = 0;
        
        for (i = 0; i < numWorkers; i++) 
			cin >> morningHours[i];

        sort(morningHours.begin(), morningHours.begin() + numWorkers);
        
        for (i = 0; i < numWorkers; i++)
			cin >> eveningHours[i];

        sort(eveningHours.begin(), eveningHours.begin() + numWorkers, greater<int>());
        
        for (i = 0; i < numWorkers; i++)
		{
            int totalHours = morningHours[i] + eveningHours[i];
            if (totalHours > regularHours)
			{
                overtime = (totalHours - regularHours) * ratePerHour;
                totalPay += overtime;
            }
        }
        cout << totalPay << "\n";
    }
    return (0);
}
