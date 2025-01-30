#include <iostream>
#include <vector>
#include <queue>
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

void Graph::bfs(const vector<vector<int>> &adjList, vector<bool> &visited, const int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (const auto neighbour : adjList[curr])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}