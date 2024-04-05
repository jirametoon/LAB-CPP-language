#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<string> &map, vector<vector<int>> &visited, int i, int j)
{
    int n = map.size();
    int m = map[0].size();
    
    visited[i][j] = 1;
    if (j + 1 < m && i + 1 < n && map[i][j] == '.' && map[i][j + 1] == '.' && map[i + 1][j] == '.' && map[i + 1][j + 1] == '.') { // Check for 2x2 box
        return true;
    }
    if (j + 2 < m && map[i][j + 2] == '.' && map[i + 1][j + 2] == '.' && !visited[i][j + 1]) { // rimapht
        if (dfs(map, visited, i, j + 1)) return true;
    }
    if (j - 1 >= 0 && map[i][j - 1] == '.' && map[i + 1][j - 1] == '.' && !visited[i][j - 1]) { // left
        if (dfs(map, visited, i, j - 1)) return true;
    }
    if (i - 1 >= 0 && map[i - 1][j] == '.' && map[i - 1][j + 1] == '.' && !visited[i - 1][j]) { // up
        if (dfs(map, visited, i - 1, j)) return true;
    }
    if (i + 2 < n && map[i + 2][j] == '.' && map[i + 2][j + 1] == '.' && !visited[i + 1][j]) { // down
        if (dfs(map, visited, i + 1, j)) return true;
    }
    return false;
}

int main(void)
{
    int n, m;
    bool CanGo = false;
    cin >> n >> m;

    vector<string>		map(n);
    vector<vector<int>>	visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        cin >> map[i];

    for (int i = 0; i < m; i++)
        if (map[0][i] == '.' && map[0][i + 1] == '.' && map[1][i] == '.' && map[1][i + 1] == '.')
		{
            CanGo = dfs(map, visited, 0, i);

            if (CanGo) 
				break;

            for (int a = 0; a < n; a++)
                for (int b = 0; b < m; b++) 
					visited[a][b] = 0;

        }

    if (CanGo)
        cout << "yes";
    else
        cout << "no";

    return (0);
}
