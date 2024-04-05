#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) 
{
    int n;
    cin >> n;

    vector<int> product(n), check(301);
    for (int i = 0; i < n; i++)
        cin >> product[i];

    sort(product.begin(), product.end(), greater<int>());

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int inDex = product[i] + product[j];
            if (check[inDex] != 0) 
            {
                cout << inDex;
                return (0);
            }
            check[inDex]++;
        }

    cout << 0;
    return (0);
}
