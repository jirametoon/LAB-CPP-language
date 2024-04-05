#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void initializeReachable(vector<vector<vector<bool>>> &reachable, const vector<string> &grid, int numRows, int numCols)
{
    for (int col = 0; col < numCols; col++)
	{
        int row = 0;
        while (row < numRows && grid[row][col] != '#')
		{
            if (grid[row][col] == '$')
                reachable[row][col][1] = true;
            row++;
        }

        row = numRows - 1;
        while (row >= 0 && grid[row][col] != '#')
		{
            if (grid[row][col] == '$')
                reachable[row][col][0] = true;
            row++;
        }
    }
}

int countReachable(const vector<string> &grid, int numRows, int numCols)
{
    int count = 0;
    for (int r = 0; r < numRows - 1; r++)
        for (int c = 0; c < numCols; c++)
            if (grid[r][c] == '$')
                count++;

    return (count);
}

int main(void)
{
    int numRows, numCols;
    cin >> numCols >> numRows;

    vector<string> grid(numRows);
    for (int i = 0; i < numRows; ++i)
        cin >> grid[i];

    vector<vector<vector<bool>>> reachable(numRows, vector<vector<bool>>(numCols, vector<bool>(2, false)));

    initializeReachable(reachable, grid, numRows, numCols);

    for (int c = 0; c < numCols; c++)
        cout << reachable[0][c][0];
    cout << "\n";

    for (int c = 0; c < numCols; c++)
        cout << reachable[0][c][1];
    cout << "\n";

    // cout << countReachable(grid, numRows, numCols) << "\n";

    return (0);
}
