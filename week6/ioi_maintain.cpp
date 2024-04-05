#include <iostream>
#include <vector>
#include <queue>
#include <set> 

using namespace std;

int main(void)
{
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<int> parents(numVertices + 1);

    for (int i = 1; i <= numVertices; ++i)
        parents[i] = i;

    using Edge = pair<int, pair<int, int>>;
    set<Edge> graph;

    int vertex1, vertex2, weight;
    for (int i = 0; i < numEdges; i++) 
	{
        cin >> vertex1 >> vertex2 >> weight;
        
        int totalCost = 0;
        graph.insert(make_pair(weight, make_pair(vertex1, vertex2)));

        for (const auto& edge : graph) 
		{
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;

            int a = u, b = v;
            while (parents[a] != a)
			{
                parents[a] = parents[parents[a]];
                a = parents[a];
            }
            while (parents[b] != b)
			{
                parents[b] = parents[parents[b]];
                b = parents[b];
            }

            if (a != b)
			{
                totalCost += w; 
                parents[a] = parents[b];
            }
        }

        int rootParent = parents[1];

        for (int i = 1; i <= numVertices; i++)
		{
            int a = i;
            while (parents[a] != a)
			{
                parents[a] = parents[parents[a]];
                a = parents[a];
            }
            if (rootParent != parents[a])
			{
                totalCost = -1;
                break;
            }
        }

        cout << totalCost << "\n";
    }

    return (0);
}
