#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	size_t		m, num;
	char	c;
	cin >> m;

	vector<int>	lst;

	for (size_t i = 0; i < m; i++)
	{
		cin >> c >> num;
		if (c == 'I')
			lst.insert(lst.begin(), num);
		else if (c == 'A')
			lst.push_back(num);
		else if (c == 'D')
			if (num <= lst.size())
				lst.erase(lst.begin() + num - 1);
	}	

	for (int val : lst)
		cout << val << "\n";
	return (0);
}

