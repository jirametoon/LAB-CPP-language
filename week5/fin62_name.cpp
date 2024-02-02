#include <iostream>
#include <string>
using namespace std;

int	main(void)
{
	size_t	index = 0, count = 0;
	string	name, word;
	cin >> name >> word;

	for (size_t i = 0; i < word.size(); i++)
	{
		if (index == name.size())
		{
			index = 0;
			count++;
		}
		if (name[index] == word[i])
			index++;
	}

	cout << count;
	return  (0);
}