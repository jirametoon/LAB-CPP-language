#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int	main(void)
{
	size_t	n, tmp;

	queue<size_t>	cards, deck;

	while (cin >> n && n)
		cards.push(n);

	while (!cards.empty())
	{
		for (size_t j = 0; j < cards.front(); j++)
			deck.push(j + 1);
		cout << "Discarded cards: ";
		while (deck.size() > 1)
		{
			cout << deck.front();
			deck.pop();
			if (deck.size() > 1)
				cout << ", ";
			else 
				break ;
			tmp = deck.front();
			deck.pop();
			deck.push(tmp);
		}
		cout << "\n" << "Remaining card: " << deck.front() << "\n";
		deck.pop();
		cards.pop();
	}

	return (0);
}