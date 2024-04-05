#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;

void constructAscending(const vector<int> &numbers, vector<int> &length)
{
    for (int i = 0; i < N; ++i)
        length[i] = 1;

    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        int inc = length[i] + 1;

        for (int j = 0; j < i; ++j)
            if (numbers[j] < numbers[i])
                length[j] = max(length[j], inc);
    }
}

void constructDescending(vector<int> &numbers, vector<int> &length)
{
    vector<int> L;

    for (int i = 0; i < int(numbers.size()); ++i)
    {
        const int num = numbers[i];
        int pos = lower_bound(L.begin(), L.end(), num) - L.begin();

        if (pos == int(L.size()))
            L.push_back(num);
        else
            L[pos] = num;

        length[i] = pos + 1;
    }
}

int main(void)
{
    vector<int> numbers, reversed, lengthAscending, lengthDescending;

    int T;
    cin >> T;

    while (T--)
    {
        cin >> N;
        numbers.resize(N);
        reversed.resize(N);
        lengthAscending.resize(N);
        lengthDescending.resize(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> numbers[i];
            reversed[N - i - 1] = numbers[i];
        }

        constructAscending(numbers, lengthAscending);
        constructDescending(reversed, lengthDescending);

        int maxLength = 0;

        for (int i = 0; i < N; ++i)
            maxLength = max(maxLength, lengthAscending[i] + lengthDescending[N - i - 1] - 1);

        cout << maxLength << '\n';
    }
    return (0);
}
