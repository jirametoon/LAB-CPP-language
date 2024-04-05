#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, max = 0, curr = 0;
	long long x, y, z;
	cin >> n;

	vector<vector<long long>> foods;
	vector<int> times(3);

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		foods.push_back({x, y, z});
	}
		
	
	return (0);
}