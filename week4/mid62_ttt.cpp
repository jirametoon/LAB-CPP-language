#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<int> G[], vector<pair<int,int>> &match, int n, int m)
{
    vector<int> color(n + 1, 0);
    queue<int> q;
    q.push(1);
    color[1] = 1;

    while (!q.empty())
	{
        int u = q.front();
        q.pop();

        for (auto v : G[u])
		{
            if (u == match[m].first && v == match[m].second)
				continue;

            if (v == match[m].first && u == match[m].second)
				continue;

            if (color[u] == color[v]) 
                return false;

            if (!color[v])
			{
                color[v] = 3 - color[u];
                q.push(v);
            }
        }
    }
    return (true);
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> match(m);
    vector<int> G[n + 1];

    for (int i = 0; i < m; i++)
	{
        cin >> match[i].first >> match[i].second;
        G[match[i].first].push_back(match[i].second);
        G[match[i].second].push_back(match[i].first);
    }

    for (int i = 0; i < m; i++) 
        if (bfs(G, match, n, i)) 
            cout << match[i].first << " " << match[i].second;

    return 0;
}
