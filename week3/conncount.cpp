#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<size_t> &visited, vector<vector<size_t>> &graph, size_t num)
{
	visited[num]++;
	for (size_t i = 0; i < graph[num].size(); i++)
		if (!visited[graph[num][i]])
			dfs(visited, graph, graph[num][i]);
}

int	main(void)
{
	size_t	n, m, a, b, res = 0;
	cin >> n >> m;

	vector<size_t>			visited(n, 0);
	vector<vector<size_t>>	graph(n);
	
	while (m--)
	{
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	for (size_t i = 0; i < n; i++)
		if (!visited[i])
		{
			res++;
			dfs(visited, graph, i);
		}

	cout << res;
	return (0);
}