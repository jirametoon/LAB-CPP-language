#include <iostream>
#include <queue>
using namespace std;

void solve(int n)
{
    queue<int> cards;

    for (int i = 1; i <= n; i++)
        cards.push(i);

    cout << "Discarded cards:";
    while (cards.size() > 1)
	{
        cout << " " << cards.front();
        cards.pop();

        int x = cards.front();
        cards.pop();

        if (!cards.empty())
            cout << ",";
			
        cards.push(x);
    }
    cout << "\nRemaining card: " << cards.front() << endl;
}

int main(void)
{
    int num_cards;

    while (cin >> num_cards, num_cards)
        solve(num_cards);

    return (0);
}
