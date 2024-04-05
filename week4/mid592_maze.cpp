#include<iostream>
#include<vector>
using namespace std;

vector<char> maze[21];
bool visited[21][21];
int n, q;
char cell;
int i, j;
int startRow, startCol, destRow, destCol;
bool canReachDestination = false;

void resetVisited()
{
    for (int r = 0; r < 21; r++)
        for (int c = 0; c < 21; c++)
            visited[r][c] = false;
}

void explore(int row, int col, bool hasKey)
{
    if (row == destRow && col == destCol)
	{
        canReachDestination = true;
        return ;
    }

    if (row < 0 || row >= n || col < 0 || col >= n)
        return ;

    if (visited[row][col] || maze[row][col] == '#')
        return ;

    if (maze[row][col] == 'O') 
	{
        if (!hasKey)
            hasKey = true;
		else
            return ;
    }

    visited[row][col] = true;

    explore(row - 1, col, hasKey);
    explore(row + 1, col, hasKey);
    explore(row, col - 1, hasKey);
    explore(row, col + 1, hasKey);
}

void checkReachability()
{
    for (int idx = 0; idx < q; idx++)
	{
        resetVisited();
        canReachDestination = false;
        cin >> startRow >> startCol >> destRow >> destCol;
        explore(startRow - 1, startCol - 1, false);

        if (canReachDestination)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

int main(void) 
{
    cin >> n >> q;
    for (int row = 0; row < n; row++)
        for (int col = 0; col < n; col++)
		{
            cin >> cell;
            maze[row].push_back(cell);
        }
		
    checkReachability();
    return (0);
}
