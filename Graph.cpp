#include <iostream>
#include <vector>
using namespace std;

#include "Graph.h"

void Graph::dfs(const vector<vector<int>> &adjList, vector<bool> &visited, const int start)
{
    visited[start] = true;
    cout << start << " ";

    for (const auto neighbour : adjList[start])
    {
        if (!visited[neighbour])
        {
            dfs(adjList, visited, neighbour);
        }
    }
}