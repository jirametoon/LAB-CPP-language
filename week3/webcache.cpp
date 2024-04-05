#include <iostream>
#include <set>
#include <queue>
using namespace std;

int is_miss(size_t num, set<size_t> &cache, queue<size_t> &last, size_t n)
{
    if (cache.find(num) == cache.end())
    {
        if (cache.size() == n)
        {
            cache.erase(last.front());
            last.pop();
        }

        cache.insert(num);
        last.push(num);
        return (1);
    }

    return (0);
}

int main(void)
{
    size_t  n, m, num, miss = 0;
    cin >> n >> m;

    set<size_t>  cache;
    queue<size_t>          last;

    while (m--)
    {
        cin >> num;

        miss += is_miss(num, cache, last, n);
    }

    cout << miss;
    return (0);
}