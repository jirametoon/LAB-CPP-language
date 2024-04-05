#include <iostream>
using namespace std;

#define MAX_AMOUNT 7490

int main(void)
{
    int coin_types[5] = {1, 5, 10, 25, 50};
    int dp[MAX_AMOUNT] = {1};

    for (int i = 0; i < 5; i++)
        for (int j = coin_types[i]; j < MAX_AMOUNT; j++)
            dp[j] += dp[j - coin_types[i]];

    int amount;
    while (cin >> amount)
        cout << dp[amount] << endl;

    return (0);
}
