#include<iostream>
using namespace std;

void traverse(char grid[][101], bool visited[][101], int numRows, int numCols, int row, int col, int &countEach, int &keepDollar, int &keepAsterisk)
{
    if (row < 0 || row >= numRows || col < 0 || col >= numCols || visited[row][col])
        return ;

    visited[row][col] = true;
    countEach++;

    if (grid[row][col] == '$')
        keepDollar = 1;
	else if (grid[row][col] == '*')
        keepAsterisk = 1;

    traverse(grid, visited, numRows, numCols, row - 1, col, countEach, keepDollar, keepAsterisk);
    traverse(grid, visited, numRows, numCols, row + 1, col, countEach, keepDollar, keepAsterisk);
    traverse(grid, visited, numRows, numCols, row, col - 1, countEach, keepDollar, keepAsterisk);
    traverse(grid, visited, numRows, numCols, row, col + 1, countEach, keepDollar, keepAsterisk);
}

int main(void)
{
    int numRows, numCols;
    cin >> numRows >> numCols;

    char grid[101][101];
    bool visited[101][101] = {{false}};

    int normalSpace = 0;
    int highSpace = 0;

    for (int i = 0; i < numRows; i++)
        for (int j = 0; j < numCols; j++)
		{
            cin >> grid[i][j];
            if (grid[i][j] == '#')
                visited[i][j] = true;
		}

    for (int i = 0; i < numRows; i++)
	{
        for (int j = 0; j < numCols; j++) 
		{
            if (!visited[i][j]) 
			{
                int countEach = 0;
                int keepDollar = 0;
                int keepAsterisk = 0;

                traverse(grid, visited, numRows, numCols, i, j, countEach, keepDollar, keepAsterisk);

                if (keepDollar && keepAsterisk)
                    highSpace += countEach;
				else if (keepDollar || keepAsterisk)
                    normalSpace += countEach;
            }
        }
    }

    cout << highSpace << ' ' << normalSpace;

    return (0);
}
