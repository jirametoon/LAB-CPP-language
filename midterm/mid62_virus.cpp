#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    int len, num_ops, val, op;
    cin >> len >> num_ops;

    vector<int> data;
	
    int virus_index = 0;
    data.reserve(len);

    for (int i = 0; i < len; i++)
	{
        cin >> val;
        data.push_back(val);
    }

    for (int i = 0; i < num_ops; i++)
	{
        cin >> op;
        if (op == 1) 
            virus_index = 0;
		else if (op == 2) 
            virus_index = (virus_index + 1) % len;
		else if (op == 3) 
		{
            cin >> val;
            data.insert(data.begin() + virus_index, val);
            virus_index = (virus_index + 1) % (len + 1);
        }
		else if (op == 4) 
		{
            cin >> val;
            data.insert(data.begin() + virus_index + 1, val);
        }
    }

    for (auto element : data)
        cout << element << "\n";

    return (0);
}
