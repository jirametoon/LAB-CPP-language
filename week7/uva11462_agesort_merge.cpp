#include <iostream>
#include <vector>
using namespace std;

void	merge(vector<int> &lst, int left, int mid, int right)
{
	int	size_left = mid - left + 1;
	int	size_right = right - mid;

	vector<int>	left_lst(lst.begin() + left, lst.begin() + mid + 1);
	vector<int>	right_lst(lst.begin() + mid + 1, lst.begin() + right + 1);

	int i = 0, j = 0, k = left;
    while (i < size_left && j < size_right)
	{
        if (left_lst[i] <= right_lst[j]) 
            lst[k++] = left_lst[i++];
        else
            lst[k++] = right_lst[j++];
    }

	while (i < size_left)
        lst[k++] = left_lst[i++];

	while (j < size_right)
		lst[k++] = right_lst[j++];
}

void	merge_sort(vector<int> &lst, int left, int right)
{
	if (left < right)
	{
		int	mid = left + (right - left) / 2;

		merge_sort(lst, left, mid);
		merge_sort(lst, mid + 1, right);

		merge(lst, left, mid, right);
	}
}

int	main(void)
{
	int	n;

	vector<vector<int>>	data;
	
	while ((cin >> n) && n)
	{
		vector<int>	lst(n);

		for (int i = 0; i < n; i++)
			cin >> lst[i];
		
		merge_sort(lst, 0, lst.size() - 1);

		data.push_back(lst);
	}

	for (size_t i = 0; i < data.size(); i++)
	{
		int	size_lst = data[i].size();

		for (int j = 0; j < size_lst; j++)
		{
			cout << data[i][j];
			if (j != size_lst - 1)
				cout << " ";
		}
		cout << "\n";
	}
	return (0);
}