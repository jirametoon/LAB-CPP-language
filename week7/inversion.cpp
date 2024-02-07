#include <iostream>
#include <vector>
using namespace std;

long long	merge(vector<long long> &lst, int left, int mid, int right)
{
    long long count = 0;
    int size_left = mid - left + 1;
    int size_right = right - mid;

    vector<long long>	lst_left(lst.begin() + left, lst.begin() + mid + 1);
    vector<long long>	lst_right(lst.begin() + mid + 1, lst.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < size_left && j < size_right)
	{
        if (lst_left[i] <= lst_right[j])
            lst[k++] = lst_left[i++];
        else
		{
            lst[k++] = lst_right[j++];
            count += size_left - i;
        }
    }

    while (i < size_left)
        lst[k++] = lst_left[i++];

    while (j < size_right)
        lst[k++] = lst_right[j++];

    return (count);
}

long long	merge_sort(vector<long long> &lst, int left, int right)
{
	long long	count = 0;

	if (left < right)
	{
		int	mid = left + (right - left) / 2;

		count += merge_sort(lst, left, mid);
		count += merge_sort(lst, mid + 1, right);
		count += merge(lst, left, mid, right);
	}

	return (count);
}

int	main(void)
{
	int	n;
	cin >> n;

	vector<long long>	lst(n);

	for (int i = 0; i < n; i++)
		cin >> lst[i];

	cout << merge_sort(lst, 0, lst.size() - 1);
	return (0);
}