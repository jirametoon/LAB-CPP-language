#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool	dfsCycle(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &recStack, int n)
{
    if (!visited[n])
	{
        visited[n] = true;
        recStack[n] = true;

        for (size_t i = 0; i < graph[n].size(); i++)
		{
            if (!visited[graph[n][i]] && dfsCycle(graph, visited, recStack, graph[n][i]))
                return true;
            else if (recStack[graph[n][i]])
                return true;
        }
    }
    recStack[n] = false;
    return (false);
}

void	dfs(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &res, int n)
{
	visited[n] = true;

	for (size_t i = 0; i < graph[n].size(); i++)
	{
		if (!visited[graph[n][i]])
			dfs(graph, visited, res, graph[n][i]);
	}
	res.push(n + 1);
}

bool	topo(vector<vector<int>> &graph, const vector<pair<int, int>> &order, int size, stack<int> &res)
{
	vector<bool>	visited_c(size, false), visited(size, false), recStack(size, false);

	for (auto pair : order) 
        if (!visited_c[pair.second]) 
            if (dfsCycle(graph, visited_c, recStack, pair.second))
                return (false);

	for (auto pair : order)
	{
		if (!visited[pair.second])
			dfs(graph, visited, res, pair.second);
	}
	return (true);
}

int	main(void)
{
	int n, m, u, v;
	cin >> n >> m;

	vector<vector<int>>		graph(n);
	vector<pair<int, int>>	order;
	stack<int>				res;

	while (m--)
	{
		cin >> u >> v;

		graph[u - 1].push_back(v - 1);
	}

	for (int i = 0; i < n; i++)
		order.push_back({graph[i].size(), i});

	sort(order.begin(), order.end());

	if (topo(graph, order, n, res))
		while (!res.empty())
		{
			cout << res.top() << "\n";
			res.pop();
		}
	else
		cout << "no";
	return (0);
}