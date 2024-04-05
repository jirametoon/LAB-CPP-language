#include <iostream>
#include <cstring>
using namespace std;

const int MAX_ROWS = 205;
int rows, cols, k;
int grid[MAX_ROWS][MAX_ROWS];
int dp[MAX_ROWS][MAX_ROWS][MAX_ROWS];

int maxScore(int row, int col, int kLeft) 
{
    if (row == rows + 1 || col == 0 || col == cols + 1)
        return (0);

    if (dp[row][col][kLeft] != 0)
        return (dp[row][col][kLeft]);

    if (kLeft > 0)
        return (dp[row][col][kLeft] = max(maxScore(row + 1, col - 1, kLeft - 1) + grid[row][col], max(maxScore(row + 1, col, kLeft) + grid[row][col], maxScore(row + 1, col + 1, kLeft - 1) + grid[row][col])));
    return (dp[row][col][kLeft] = maxScore(row + 1, col, kLeft) + grid[row][col]);
}

int main(void) 
{
    cin >> rows >> cols >> k;
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= cols; j++)
            cin >> grid[i][j];

    int maximum = 0;
    for (int i = 1; i <= cols; i++)
        maximum = max(maxScore(1, i, k), maximum);

    cout << maximum;
    return (0);
}
