#include <iostream>
using namespace std;

int Primes[5200], PrimeCount;
int ways[1121][15] = {};

void sieve()
{
    char mark[10000] = {};
    PrimeCount = 0;

    for(int i = 2; i < 10000; i++)
        if(mark[i] == 0) 
		{
            Primes[PrimeCount++] = i;

            for(int j = 2; i * j < 10000; j++)
                mark[i * j] = 1;
        }
}

void computeWays()
{
    ways[0][0] = 1;

    for(int i = 0; i < PrimeCount; i++)
        for(int j = 1120; j >= Primes[i]; j--)
            for(int k = 14; k >= 1; k--)
                ways[j][k] += ways[j - Primes[i]][k - 1];
}

int main(void)
{
    sieve();
    computeWays();
    int n, m;

    while(cin >> n >> m)
	{
        if(n == 0 && m == 0)
            break;

        cout << ways[n][m] << endl;
    }
    return (0);
}
