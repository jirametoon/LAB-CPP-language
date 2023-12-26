#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int main(void)
{
    size_t  n, m, num, miss = 0;
    cin >> n >> m;

    unordered_set<size_t>  cache;
    queue<size_t>          last;

    while (m--)
    {
        cin >> num;

        auto it = cache.find(num);

        if (it == cache.end())
        {
            if (cache.size() == n)
            {
                cache.erase(last.front());
                last.pop();
            }
            cache.insert(num);
            last.push(num);
            miss++;
        }
    }

    cout << miss << "\n";
    return (0);
}