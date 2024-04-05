#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) 
{
    int rows, columns, start_r, start_c, end_r, end_c; 
    int i, j;

    vector<vector<int>> countries;
    vector<bool> visited;
    vector<int> distance_from_start;
    vector<vector<int>> adjacency_list;

    cin >> rows >> columns >> start_r >> start_c >> end_r >> end_c;
    countries.resize(rows + 1, vector<int>(columns + 1));
    visited.resize(rows * columns + 1, false);
    distance_from_start.resize(rows * columns + 1, 0);
    adjacency_list.resize(rows * columns + 1);

    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            cin >> countries[i][j];

    for (int i = 1; i < rows; i++)
	{
        for (int j = 1; j <= columns; j++)
		{
            int curr = countries[i][j];
            int down = countries[i + 1][j]; 

            if (j == columns) 
			{
                if (curr != down) 
				{
                    adjacency_list[curr].push_back(down);
                    adjacency_list[down].push_back(curr); 
                }

                continue;
            }

            int right = countries[i][j + 1];

            if (curr != right) 
			{
                adjacency_list[curr].push_back(right); 
                adjacency_list[right].push_back(curr); 
            }
            
            if (curr != down) 
			{
                adjacency_list[curr].push_back(down);
                adjacency_list[down].push_back(curr); 
            }
        }
    }

    queue<int> q;
    visited[countries[start_r][start_c]] = true;
    q.push(countries[start_r][start_c]);
    distance_from_start[countries[start_r][start_c]] = 0;

    while (!q.empty()) 
	{
        int curr = q.front();
        q.pop();

        for (int i = 0; i < adjacency_list[curr].size(); i++) 
		{
            int next = adjacency_list[curr][i];

            if (!visited[next]) 
			{
                visited[next] = true;
                distance_from_start[next] = distance_from_start[curr] + 1;
                q.push(next);
            }
        }
    }

    cout << distance_from_start[countries[end_r][end_c]];
    return (0);
}
