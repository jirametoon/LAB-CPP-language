#include <iostream>
#include <vector>
using namespace std;

void readInput(vector<int> &numbers, int &shifts)
{
    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) 
	{
        int x;
        cin >> x;
        numbers.push_back(x);
    }

    int existingElements = numbers.size();

    for (int i = 1; i <= 20 - existingElements; i++)
        numbers.push_back(i);

    shifts = s;
}

void rotateList(vector<int> &numbers, int shifts) 
{
    for (int i = 0; i < shifts; i++) 
	{
        int t = numbers.back();

        numbers.pop_back();
        numbers.insert(numbers.begin(), t);
    }
}

void printMatrix(const vector<int> &numbers) 
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cout << numbers[j * 5 + i] << " ";
        }
    }
}

int main(void) 
{
    vector<int> list;
    int shifts;
    readInput(list, shifts);
    rotateList(list, shifts);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 4; j++)
            cout << list[j * 5 + i] << " ";

    return (0);
}
