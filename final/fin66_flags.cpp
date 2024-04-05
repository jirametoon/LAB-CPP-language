#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<long long>& height, int left, int mid, int right) {
    long long count = 0;
    int i = left, j = mid + 1;
    vector<long long> temp(right - left + 1);
    int k = 0;

    // Count triplets and merge
    while (i <= mid && j <= right) {
        if (height[i] <= height[j]) {
            temp[k++] = height[i++];
        } else {
            count += (mid - i + 1) * 1LL;  // Count triplets
            temp[k++] = height[j++];
        }
    }

    // Copy remaining elements from the left subarray
    while (i <= mid) {
        temp[k++] = height[i++];
    }

    // Copy remaining elements from the right subarray
    while (j <= right) {
        temp[k++] = height[j++];
    }

    // Copy the merged elements back to the original array
    for (int p = 0; p < k; p++) {
        height[left + p] = temp[p];
    }

    return count;
}

long long countTriplets(vector<long long>& height, int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += countTriplets(height, left, mid);
        count += countTriplets(height, mid + 1, right);
        count += mergeAndCount(height, left, mid, right);
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<long long> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    long long count = countTriplets(height, 0, n - 1);
    cout << count << endl;

    return 0;
}
