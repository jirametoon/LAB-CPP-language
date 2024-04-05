#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

long long total_value(vector<vector<int>> &plays, set<int> &myset, int n, int size)
{
	
    return ();
}

int main(void)
{
	int n, m, a, b, c;
	cin >> n >> m;

	vector<vector<int>>	plays;
	set<int> myset;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		plays.push_back({c, a, b});
	}

	sort(plays.begin(), plays.end());

	cout << total_value(plays, myset, n, m);

	return (0);
}