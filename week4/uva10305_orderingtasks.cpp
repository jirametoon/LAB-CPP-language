#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void traverseGraph(vector<bool> &tasksVisited, const vector<vector<int>> &dependencyGraph, vector<int> &order, int node)
{
    tasksVisited[node] = true;

    for (int i = 0; i < dependencyGraph[node].size(); i++) 
	{
        int nextNode = dependencyGraph[node][i];

        if (!tasksVisited[nextNode])
            traverseGraph(tasksVisited, dependencyGraph, order, nextNode);
    }
	
    order.push_back(node);
}

vector<int> topologicalSort(const vector<vector<int>> &dependencyGraph, int numNodes)
{
    vector<bool> tasksVisited(numNodes + 1, false);
    vector<int> nodeOrder;

    for (int node = 1; node <= numNodes; node++)
        if (!tasksVisited[node])
            traverseGraph(tasksVisited, dependencyGraph, nodeOrder, node);

    reverse(nodeOrder.begin(), nodeOrder.end());
    return (nodeOrder);
}

int main(void)
{
    int numNodes, numEdges;

    while (cin >> numNodes >> numEdges && !(numNodes == 0 && numEdges == 0))
	{
        vector<bool> tasksVisited(numNodes + 1, false);
        vector<vector<int>> dependencyGraph(numNodes + 1);
        vector<int> nodeOrder;

        for (int i = 0; i < numEdges; ++i)
		{
            int fromNode, toNode;
            cin >> fromNode >> toNode;

            dependencyGraph[fromNode].push_back(toNode);
        }

        nodeOrder = topologicalSort(dependencyGraph, numNodes);

        copy(nodeOrder.begin(), nodeOrder.end(), ostream_iterator<int>(cout, " "));
        cout << "\n";
    }

    return (0);
}
