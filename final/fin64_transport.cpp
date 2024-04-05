#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) 
{
    int num_points;
    cin >> num_points;
    
    vector<tuple<double, int, int>> edges;
    vector<int> parent(300000);
    vector<int> x_coords(num_points + 1), y_coords(num_points + 1);
    
    for (int i = 1; i <= num_points; i++) 
	{
        cin >> x_coords[i] >> y_coords[i];

        for (int j = 1; j < i; j++) 
		{
            double dx = x_coords[i] - x_coords[j];
            double dy = y_coords[i] - y_coords[j];
            double distance = sqrt(dx * dx + dy * dy);
            edges.push_back({distance, i, j});
        }
    }
    
    for (int i = 1; i <= num_points; i++)
        parent[i] = i;
    
    sort(edges.begin(), edges.end());
    
    double total_distance = 0;
    double last_edge_weight = 0;

    for (auto edge : edges) 
	{
        double weight;
        int u, v;

        tie(weight, u, v) = edge;

        if (parent[u] == parent[v])
            continue;

        total_distance += weight;
        last_edge_weight = weight;
        u = parent[u];
        v = parent[v];
        parent[u] = v;
    }
    
    cout << fixed;
    cout.precision(4);
    cout << total_distance - last_edge_weight;
    return (0);
}
