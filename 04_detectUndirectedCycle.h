#ifndef UNDIRECTED_CYCLE
#define UNDIRECTED_CYCLE

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isCycle(vector<vector<int>> &adj)
    {
        vector<bool> visited(adj.size(), false);
        for (int i = 0; i < adj.size(); i++)
        {
            // if (!visited[i] && dfsMode(adj, visited, -1, i))
            if (!visited[i] && bfsMode(adj, visited, i))
                return true;
        }

        return false;
    }

    bool dfsMode(vector<vector<int>> &adjList, vector<bool> &visited, int parent, int start)
    {
        visited[start] = true;

        for (auto neighbour : adjList[start])
        {
            if (!visited[neighbour])
            {
                if (dfsMode(adjList, visited, start, neighbour))
                    return true;

                // both if statement can't be combined because if inner statement becomes false
                // it is expected to go to next neighbour and repeat the process but
                // it will go to else part and compare and might return true for some cases
            }
            else if (parent != neighbour)
                return true;
        }

        return false;
    }

    bool bfsMode(vector<vector<int>> &adjList, vector<bool> &visited, int start)
    {
        vector<int> parent(adjList.size(), -1);

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto neighbour : adjList[curr])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                    parent[neighbour] = curr;
                }
                else if (parent[curr] != neighbour)
                    return true;
            }
        }

        return false;
    }
};

#endif