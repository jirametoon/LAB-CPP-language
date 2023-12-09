#include <iostream>
#include <vector>
#include <string>
using namespace std;

int	main(void)
{
	int	m, num;
	string	str;
	cin >> m;

	vector<int> lst;
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (str == "li")
		{
			cin >> num;
			lst.insert(lst.begin(), num);
		}
		else if (str == "ri")
		{
			cin >> num;
			lst.push_back(num);
		}
		else if (str == "lr" && lst.size() != 0)
		{
			num = lst.front();
			lst.erase(lst.begin());
			lst.push_back(num);
		}
		else if (str == "rr" && lst.size() != 0)
		{
			num = lst.back();
			lst.pop_back();
			lst.insert(lst.begin(), num);
		}
	}

	for (int val : lst)
		cout << val << "\n";
	return (0);
}