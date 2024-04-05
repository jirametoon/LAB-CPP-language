#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    int test_cases, case_num = 0;
    cin >> test_cases;

    while (test_cases--) 
	{
        ++case_num;
        int n;
        cin >> n;

        char characters[1000];
        cin.ignore();
        cin.getline(characters, 1000);

        int dots_count = 0;
        for (int i = 0; i < n; ++i)
            if (characters[i] == '.')
			{
                dots_count++;
                i += 2;
            }

        cout << "Case " << case_num << ": " << dots_count << "\n";
    }

    return (0);
}
