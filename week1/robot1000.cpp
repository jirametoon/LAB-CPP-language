#include <iostream>
#include <string>
using namespace std;

int	main(void)
{
	string	move;
	cin >> move;

	int	point[2] = {0, 0};
	for (char ch : move)
	{
		if (ch == 'N')
			point[1]++;
		else if (ch == 'S')
			point[1]--;
		else if (ch == 'E')
			point[0]++;
		else if (ch == 'W')
			point[0]--;
		else if (ch == 'Z')
			for (int i = 0; i < 2; i++)
				point[i] = 0;
	}

	for (int i = 0; i < 2; i++)
	{
		cout << point[i];
		if (!(i % 2))
			cout << " ";
	}
	return (0);
}