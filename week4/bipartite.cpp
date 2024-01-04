#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool	isBipartiteBfs(const vector<vector<size_t>> &graph, size_t startnode, vector<int> &group)
{
	queue<size_t>	q;

	q.push(startnode);
	group[startnode] = 0;

	while (!q.empty())
	{
		size_t	currentnode = q.front();
		q.pop();

		for (size_t i : graph[currentnode])
		{
			if (group[i] == -1)
			{
				group[i] = 1 - group[currentnode];
				q.push(i);
			}
			else if (group[i] == group[currentnode])
				return (false);
		}
	}
	return (true);
}

bool	isBipartite(vector<vector<size_t>> &graph, size_t n)
{
	vector<int> group(n, -1);

	for (size_t	i = 0; i < n; i++)
	{
		if (group[i] != -1)
			continue;
		if (!isBipartiteBfs(graph, i, group))
			return (false);
	}
	return (true);
}

int	main(void)
{
	size_t	k, n, m, u, v;
	cin >> k;

	vector<bool>	res;
	while (k--)
	{
		cin >> n >> m;

		vector<vector<size_t>>	graph(n);
		while (m--)
		{
			cin >> u >> v;
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}
		res.push_back(isBipartite(graph, n));
	}

	for (bool val : res)
	{
		if (val)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return (0);
}