#include <iostream>
#include <vector>
using namespace std;

void readInput(int n, vector<int> &A) 
{
    cin >> n;
    A.resize(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];
}

int maxOverlappingIntervals(int n, const vector<int> &A) 
{
    int ans = 0;
    vector<int> B(2 * n, 0);

    for (int i = 0; i < n; i++) 
	{
        if (A[i] <= i) 
		{
            B[i - A[i]]++;
            ans = max(ans, B[i - A[i]]);
        } 
		else 
		{
            B[n + i - A[i]]++;
            ans = max(ans, B[n + i - A[i]]);
        }
    }

    return (ans);
}

int main(void) 
{
    int n;
    vector<int> A;

    readInput(n, A);

    int result = maxOverlappingIntervals(n, A);

    cout << result;

    return (0);
}
