#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX_NODES = 100010;

vector<int> adjacencyList[MAX_NODES];
bool visited[MAX_NODES] = {false};
int layer[MAX_NODES] = {0};
int nodes, edges, maxDistance, maxCount;

void breadthFirstSearch(int startNode)
{
    queue<int> q;
    maxCount = 1;
    visited[startNode] = true;
    layer[startNode] = 0;
    q.push(startNode);

    while (!q.empty())
	{
        int currentNode = q.front();
        if (layer[currentNode] > maxDistance)
            break;
        q.pop();

        for (int i = 0; i < adjacencyList[currentNode].size(); i++)
		{
            int nextNode = adjacencyList[currentNode][i];
            if (!visited[nextNode]) 
			{
                visited[nextNode] = true;
                layer[nextNode] = layer[currentNode] + 1;

                if (layer[nextNode] <= maxDistance)
                    maxCount++;
                q.push(nextNode);
            }
        }
    }
}

void resetVisitedAndLayer()
{
    for (int i = 1; i <= nodes; i++)
	{
        visited[i] = false;
        layer[i] = 0;
    }
}

int main(void)
{
    cin >> nodes >> edges >> maxDistance;
    for (int i = 0; i < edges; i++)
	{
        int u, v;
        cin >> u >> v;

        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    int globalMaxCount = 0;

    for (int i = 1; i <= nodes; i++)
	{
        resetVisitedAndLayer();
        breadthFirstSearch(i);
        globalMaxCount = maxCount > globalMaxCount ? maxCount : globalMaxCount;
    }

    cout << globalMaxCount;
    return (0);
}
