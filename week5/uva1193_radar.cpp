#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N = 1500;
pair<double, double> positions[MAX_N];
int num_points, radius;

int main(void) 
{
    int case_num = 1;
    while (true) 
	{
        cin >> num_points >> radius;
        if (num_points == 0 && radius == 0)
            break;
        
        bool feasible = true;
		
        for (int i = 0; i < num_points; i++) 
		{
            int x, y;
            cin >> x >> y;

            if (y > radius)
                feasible = false;

            positions[i].first = x - sqrt(radius * radius - y * y);
            positions[i].second = x + sqrt(radius * radius - y * y);
        }

        if (!feasible) 
		{
            cout << "Case " << case_num << ": -1" << endl;
            case_num++;
            continue;
        }

        sort(positions, positions + num_points);

        int answer = 0;
        int i = 0;
        double d;
        while (i < num_points) 
		{
            d = positions[i].second;
            answer++;

            while (i < num_points && positions[i].first <= d)
			{
                if (d > positions[i].second)
                    d = positions[i].second;
                i++;
            }
        }

        cout << "Case " << case_num << ": " << answer << endl;
        case_num++;
    }
    return (0);
}
