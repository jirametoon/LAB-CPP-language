#include <iostream>
#include <stack>
using namespace std;

bool isOrderPossible(int num_coaches, int target[])
{
    int curr_coach = 1, target_index = 0;
    stack<int> station;

    while (curr_coach <= num_coaches)
	{
        station.push(curr_coach);

        while (!station.empty() && station.top() == target[target_index])
		{
            station.pop();
            target_index++;

            if (target_index >= num_coaches)
				break;
        }

        curr_coach++;
    }

    return (station.empty());
}

int main(void)
{
    int num_coaches, target[1000];

    while (true)
	{
        cin >> num_coaches;

        if (num_coaches == 0)
            break;

        while (true)
		{
            cin >> target[0];
            if (target[0] == 0)
			{
                cout << "\n";
                break;
            }

            for (int i = 1; i < num_coaches; i++)
                cin >> target[i];

            if (isOrderPossible(num_coaches, target)) 
                cout << "Yes" << "\n";
            else 
                cout << "No" << "\n";
        }
    }

    return (0);
}
