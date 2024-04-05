#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<int> price;
int n, q;

void readInput() {
    cin >> n >> q;
    price.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    sort(price.begin(), price.end());
}

int findMax(int x, int y) {
    int maxSum = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (price[i] >= y) {
            j = i;
            break;
        }
    }
    int sizeH = n - j;
    int left = j;
    int right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (maxSum + (mid - j) * price[mid] > x) {
            right = mid;
        } else {
            maxSum += (mid - j) * price[mid];
            left = mid + 1;
        }
    }
    return left - j;
}

int main() {
    readInput();

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << findMax(x, y) << endl;
    }
}