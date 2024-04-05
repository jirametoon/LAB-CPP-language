#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> price;

void readInput(int& n, int m, int l) 
{
    cin >> n >> m >> l;
    price.push_back(0);

    for (int i = 0; i < n; i++) 
	{
        int x;
        cin >> x;
        price.push_back(x);
    }
    graph.resize(n + 1);

    for (int i = 0; i < m; i++)
	{
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
}

int calculateMinimumCost(int n, int l) 
{
    vector<int> dist(n + 1, 1e9);
    queue<pair<int, int>> q;
    dist[1] = 0;
    q.push({1, 0});

    while (!q.empty()) 
	{
        int u = q.front().first;
        q.pop();

        for (auto it : graph[u]) 
		{
            int v = it.first;
            int w = it.second;

            if (dist[u] + w < dist[v]) 
			{
                dist[v] = dist[u] + w;
                q.push({v, dist[v]});
            }
        }
    }
    int sum = 0;
    for (int i = 2; i <= n; i++)
        sum += min(dist[i] * l, dist[i] * price[i]);

    return (sum);
}

int main(void) 
{
    int n, m, l;
    readInput(n, m, l);
    cout << calculateMinimumCost(n, l);
    return (0);
}
