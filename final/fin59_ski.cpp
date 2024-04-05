#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<vector<int>> ski(n, vector<int>(2));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			cin >> ski[i][j];

	return (0);
}