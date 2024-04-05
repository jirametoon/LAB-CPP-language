#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
    int cases, vertices, edges, i, j, u, v;
    int count = 0;
    cin >> cases >> vertices;
    vector<vector<int>> adjacencyList(vertices + 1);

    for (i = 0; i < cases; i++)
	{
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);

        int color[vertices + 1];
        for (i = 1; i <= vertices; i++)
            color[i] = -1;

        queue<int> q;
        q.push(1);
        color[1] = 1;

        bool isBipartite = true;

        while (!q.empty())
		{
            int node = q.front();
            int curColor = color[node];
            q.pop();

            for (i = 0; i < adjacencyList[node].size(); i++) 
			{
                int nextNode = adjacencyList[node][i];

                if (color[nextNode] == -1) 
				{
                    q.push(nextNode);
                    color[nextNode] = 1 - curColor;
                } 
				else if (color[nextNode] == curColor) 
				{
                    isBipartite = false;
                    break;
                }
            }

            if (!isBipartite)
                break;
        }

        if (isBipartite)
            count++;
        else
		{
            cout << count << endl;
            break;
        }
    }

    return (0);
}
