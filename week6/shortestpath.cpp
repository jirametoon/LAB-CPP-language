#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1000000000

void shortestPath(vector<vector<pair<size_t, size_t>>> &graph, size_t source, size_t n)
{
    vector<bool>	visited(n, false);
    vector<size_t>	distance(n, INF);

    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) 
	{
        size_t u = pq.top().second;
        pq.pop();

        if (visited[u]) 
			continue;

        visited[u] = true;

        for (const auto& edge : graph[u])
		{
            size_t v = edge.second;
            size_t weight = edge.first;

            if (!visited[v] && distance[u] + weight < distance[v])
			{
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
    
	cout << distance[n - 1];
}

int main(void)
{
    size_t n, m, x, y, w;
    cin >> n >> m;

    vector<vector<pair<size_t, size_t>>> graph(n);

    while (m--)
	{
        cin >> x >> y >> w;
        graph[x - 1].push_back({w, y - 1});
        graph[y - 1].push_back({w, x - 1});
    }

    for (size_t i = 0; i < n; i++)
        sort(graph[i].begin(), graph[i].end());

    shortestPath(graph, 0, n);
    return (0);
}
