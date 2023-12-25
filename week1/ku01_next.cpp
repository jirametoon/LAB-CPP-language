#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void	update(vector<int> &received, const vector<int> &send, vector<int> &gift, int size)
{
    for (int i = 0; i < size; i++)
    {
        gift[i] = send[gift[i]];
        if (gift[i] == i)
            received[i] = 1;
    }
}

int main(void)
{
    int	count, num, res = 0;
    cin >> count;

    vector<int>	received(count, 0), send(count), gift(count);

    for (int i = 0; i < count; i++)
    {
        cin >> num;
		gift[i] = i;
        send[--num] = i;
    }
    while (any_of(received.begin(), received.end(), [](int val) { return val == 0; }))
    {
        res++;
        update(received, send, gift, count);
    }

    cout << res;
    return 0;
}