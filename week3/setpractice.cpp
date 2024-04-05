#include <iostream>
#include <set>
#include <vector>
using namespace std;

size_t findNearestValue(const set<size_t>& myset, size_t num)
{
    if (num > *--myset.end())
        return (*--myset.end());
    else if (num < *myset.begin())
        return (*myset.begin());
    else if (num == *myset.find(num))
        return (num);
    else 
	{
        auto it1 = myset.upper_bound(num);
        auto it2 = it1--;
        if (*it2 - num >= num - *it1)
            return (*it1);
        else
            return (*it2);
    }
}

set<size_t> readInputNumbers(size_t n)
{
    set<size_t> myset;
    size_t num;

    while (n--) 
	{
        cin >> num;
        myset.insert(num);
    }
    return (myset);
}

vector<size_t> processQueries(const set<size_t>& myset, size_t m)
{
    vector<size_t> res;
    size_t num;

    while (m--) 
	{
        cin >> num;
        res.push_back(findNearestValue(myset, num));
    }
    return (res);
}

void printResult(const vector<size_t>& res)
{
    for (size_t val : res)
        cout << val << "\n";
}

int main(void) 
{
    size_t n, m;
    cin >> n >> m;

    set<size_t> myset = readInputNumbers(n);
    vector<size_t> res = processQueries(myset, m);
	
    printResult(res);

    return (0);
}
