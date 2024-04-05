#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1005

int num_items, max_weight, knapsack[MAX][MAX], values[MAX], weights[MAX];

int Knapsack()
{
    for (int i = 0; i <= num_items; i++)
        knapsack[i][0] = 0;
    for (int w = 0; w <= max_weight; w++)
        knapsack[0][w] = 0;

    for (int i = 1; i <= num_items; i++)
    {
        for (int w = 0; w <= max_weight; w++)
        {
            if (weights[i] > w)
                knapsack[i][w] = knapsack[i - 1][w];
            else
                knapsack[i][w] = max(knapsack[i - 1][w], knapsack[i - 1][w - weights[i]] + values[i]);
        }
    }
    return knapsack[num_items][max_weight];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> num_items;
        for (int i = 1; i <= num_items; i++)
            cin >> values[i] >> weights[i];
        int sum = 0;
        int num_knapsacks;
        cin >> num_knapsacks;
        while (num_knapsacks--)
        {
            cin >> max_weight;
            sum += Knapsack();
        }
        cout << sum << endl;
    }
    return 0;
}
