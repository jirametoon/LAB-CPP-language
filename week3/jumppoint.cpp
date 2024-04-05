#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

int main(void)
{
    int numPoints, radius, i, j;
    int xCoord, yCoord;

    cin >> numPoints >> radius;

    vector<int> adjacencyList[100001];
    pair<int, int> coordinates[100001];
    int layers[100001] = {-1};

    // Initialize boundary points
    coordinates[0] = make_pair(0, 0);
    coordinates[numPoints + 1] = make_pair(100, 100);

    for (i = 1; i <= numPoints; i++)
	{
        cin >> xCoord >> yCoord;
        coordinates[i] = make_pair(xCoord, yCoord);

        for (j = 0; j < i; j++)
		{
            float oldX = coordinates[j].first * 1.0;
            float oldY = coordinates[j].second * 1.0;
            float distance = sqrt((oldX - xCoord * 1.0) * (oldX - xCoord * 1.0) + (oldY - yCoord * 1.0) * (oldY - yCoord * 1.0));

            if (distance <= radius)
			{
                adjacencyList[j].push_back(i);
                adjacencyList[i].push_back(j);
            }
        }

        float oldX = coordinates[numPoints + 1].first * 1.0;
        float oldY = coordinates[numPoints + 1].second * 1.0;
        float distance = sqrt((oldX - xCoord * 1.0) * (oldX - xCoord * 1.0) + (oldY - yCoord * 1.0) * (oldY - yCoord * 1.0));

        if (distance <= radius)
		{
            adjacencyList[numPoints + 1].push_back(i);
            adjacencyList[i].push_back(numPoints + 1);
        }
    }

    queue<int> queue;
    int start = 0;
    bool visited[100000] = {false};
    layers[start] = 0;

    visited[start] = true;
    queue.push(start);

    while (!queue.empty())
	{
        int current = queue.front();
        queue.pop();

        for (size_t i = 0; i < adjacencyList[current].size(); i++)
		{
            int next = adjacencyList[current][i];

            if (!visited[next])
			{
                visited[next] = true;
                layers[next] = layers[current] + 1;
                queue.push(next);
            }
        }
    }

    cout << (layers[numPoints + 1] > 0 ? layers[numPoints + 1] : -1);
    return (0);
}
