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

bool Graph::validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    // converting edge list of a graph to adjacency list
    vector<vector<int>> adjList(n);
    for (auto edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n, false);
    // return dfsMode(adjList, visited, source, destination);
    return bfsMode(adjList, visited, source, destination);
}

bool dfsMode(const vector<vector<int>> &adjList, vector<bool> &visited, int source, int destination)
{
    if (source == destination)
        return true;
    visited[source] = true;

    for (auto neighbour : adjList[source])
    {
        if (!visited[neighbour] && dfsMode(adjList, visited, neighbour, destination))
        {
            return true;
        }
    }
    return false;
}

bool bfsMode(vector<vector<int>> &adjList, vector<bool> &visited, int source, int destination)
{
    if (source == destination)
        return true;

    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto neighbour : adjList[curr])
        {
            if (neighbour == destination)
                return true;

            else if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return false;
}