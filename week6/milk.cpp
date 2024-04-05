#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool is_connected(vector<vector<int>> &milk, int start, int end, int size)
{
    vector<bool>	visited(size, false);
    queue<int>		to_visit;

    visited[start] = true;
    to_visit.push(start);

    while (!to_visit.empty())
	{
        int current = to_visit.front();
        to_visit.pop();

        if (current == end)
            return (true);

        for (int neighbor : milk[current])
            if (!visited[neighbor]) 
			{
                visited[neighbor] = true;
                to_visit.push(neighbor);
            }
    }
    return (false);
}


int	main(void)
{
	int 	n, q, x, y;
	char	c;
	cin >> n >> q;

	vector<vector<int>>	milk(n);

	while (q--)
	{
		cin >> c >> x >> y;

		if (c == 'c')
		{
			milk[x - 1].push_back(y - 1);
			milk[y - 1].push_back(x - 1);
		}
		else if (c == 'q')
		{
			if (is_connected(milk, x - 1, y - 1, n))
				cout << "yes\n";
			else
				cout << "no\n";
		}
	}
	return (0);
}