#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

float weak_row(int row, int col, vector<vector<int>> &table, int size)
{
	float avg = 0;

	for (int i = 0; i < size; i++)
	{
		if (col == i)
			continue;
		
		avg += abs(table[row][col] - table[row][i]);
	}

	return (avg);
}

float weak_col(int row, int col, vector<vector<int>> &table, int size)
{
	float avg = 0;

	for (int i = 0; i < size; i++)
	{
		if (row == i)
			continue;
		
		avg += abs(table[row][col] - table[i][col]);
	}

	return (avg);
}

int	main(void)
{
	int 	row, col, res = 0;
	float	avg, good = INFINITY;	
	cin >> row >> col;

	vector<vector<int>> table(row, vector<int>(col));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> table[i][j];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			avg = (weak_row(i, j, table, col) + weak_col(i, j, table, row)) / (row + col - 2);

			if (avg < good)
			{
				good = avg;
				res = table[i][j];
			}
		}
	
	cout << res;
	return (0);
}