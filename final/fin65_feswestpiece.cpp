#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_M = 31;
const int MAX_N = 31;
int m, n;
int cave[MAX_M][MAX_N];
int min_sum[MAX_M][MAX_N];

int cup(int x, int y, int direction) 
{
    if (x < 0 || x >= m || y < 0 || y >= n)
        return (0);

    if (direction == 1)
        return (cave[x][y] + cup(x - 1, y, 1));
    else if (direction == 2) 
        return (cave[x][y] + cup(x, y + 1, 2));
    else if (direction == 3) 
        return (cave[x][y] + cup(x + 1, y, 3));
    else if (direction == 4) 
        return (cave[x][y] + cup(x, y - 1, 4));
}

int main(void)
{
    cin >> m >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> cave[i][j];

            if (i == 0 || j == 0)
                min_sum[i][j] = cave[i][j];
        }

    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
        {
            if (min_sum[i][j] != 0)
                continue;

            int up = cup(i, j, 1);
            int right = cup(i, j, 2);
            int down = cup(i, j, 3);
            int left = cup(i, j, 4);

            min_sum[i][j] = min(up, min(right, min(down, left)));
        }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << min_sum[i][j] << ' ';

        cout << "\n";
    }

    return (0);
}
