#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;

void readInput(int n, int m, int s, int t)
{
    cin >> n >> m >> s >> t;

    graph.resize(n + 1);
    visited.resize(n + 1, -1);

    for (int i = 0; i < m; i++) 
	{
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

void bfs(int s) 
{
    queue<pair<int, int>> q;
    for (int i = 0; i < s; i++) 
	{
        int x;
        cin >> x;
        q.push({x, 0});
        visited[x] = 0;
    }

    while (!q.empty())
	{
        int u = q.front().first;
        int st = q.front().second;
        q.pop();

        for (auto v : graph[u]) 
		{
            if (visited[v] != -1)
                continue;

            visited[v] = st + 1;
            q.push({v, visited[v]});
        }
    }
}

void processQueries(int t) 
{
    for (int i = 0; i < t; i++) 
	{
        int x;
        cin >> x;
        cout << visited[x] << "\n";
    }
}

int main(void) 
{
    int n, m, s, t;
    readInput(n, m, s, t);
    bfs(s);
    processQueries(t);
    return (0);
}
