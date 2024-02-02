#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool	safe(int x, int y, int n, vector<vector<int>> &maze)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
	       return (false);
	if (maze[x][y] == 1)
	{
		maze[x][y] = 2;
		return (true);
	}
	return (false);
}

int	path_count(int x, int y, int n, vector<vector<int>> &maze, int use, int count)
{
	while (!(x == n - 1 && y == n - 1))
	{
		if (safe(x + 1, y, n, maze)) 
        	return (path_count(x + 1, y, n, maze, 1, count + 1));
		if (safe(x, y + 1, n, maze))
        	return (path_count(x, y + 1, n, maze, 1, count + 1));
		if (safe(x - 1, y, n, maze)) 
        	return (path_count(x - 1, y, n, maze, 1, count + 1));
		if (safe(x, y - 1, n, maze))
        	return (path_count(x, y - 1, n, maze, 1, count + 1));
		if (use)
		{
			if (safe(x - 2, y - 1, n, maze)) 
        		return (path_count(x - 2, y - 1, n, maze, 0, count + 1));
			if (safe(x - 2, y + 1, n, maze))
				return (path_count(x - 2, y + 1, n, maze, 0, count + 1));
			if (safe(x - 1, y - 2, n, maze)) 
				return (path_count(x - 1, y - 2, n, maze, 0, count + 1));
			if (safe(x - 1, y + 2, n, maze))
				return (path_count(x - 1, y + 2, n, maze, 0, count + 1));
			if (safe(x + 1, y - 2, n, maze)) 
        		return (path_count(x + 1, y - 2, n, maze, 0, count + 1));
			if (safe(x + 1, y + 2, n, maze))
				return (path_count(x + 1, y + 2, n, maze, 0, count + 1));
			if (safe(x + 2, y - 1, n, maze)) 
				return (path_count(x + 2, y - 1, n, maze, 0, count + 1));
			if (safe(x + 2, y + 1, n, maze))
				return (path_count(x + 2, y + 1, n, maze, 0, count + 1));
		}
		maze[x][y] = 1;
        return (0);
    }
    return (count);
}


int	main(void)
{
	int	n;
	string	s;
	cin >> n;

	vector<vector<int>>	maze(n);

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (auto ch : s)
		{
			if (ch == '.')
				maze[i].push_back(1);
			else
				maze[i].push_back(0);
		}
	}

	cout << path_count(0, 0, n, maze, 1, 0) << "\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j] == 0)
				cout << '#';
			else if (maze[i][j] == 1)
				cout << ' ';
			else
				cout << '.';
		}
		cout << "\n";
	}
	return (0);
}