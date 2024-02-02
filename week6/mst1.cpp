#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void mst(const vector<vector<pair<size_t, size_t>>>& graph, size_t source, size_t n)
{
    vector<bool>	visited(n, false);

    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>>	pq;

    visited[source] = true;

    for	(const auto& edge : graph[source])
        pq.push({edge.first, edge.second});

    size_t	totalWeight = 0;

    while (!pq.empty())
	{
        size_t	weight = pq.top().first;
        size_t	to = pq.top().second;
        pq.pop();

        if (!visited[to])
		{
            totalWeight += weight;
            visited[to] = true;

            for (const auto& edge : graph[to])
                if (!visited[edge.second])
                    pq.push({edge.first, edge.second});
        }
    }
	
    cout << totalWeight;
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

    mst(graph, 0, n);
    return (0);
}
