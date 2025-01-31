#ifndef REROUTE
#define REROUTE

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> forwardList(n);
        vector<vector<int>> backwardList(n);

        for (auto connection : connections)
        {
            forwardList[connection[0]].push_back(connection[1]);
            backwardList[connection[1]].push_back(connection[0]);
        }

        int targetCity = 0;
        // return bfsMode(forwardList, backwardList, targetCity);

        int routeChanged = 0;
        vector<bool> visited(n, false);
        dfsMode(forwardList, backwardList, visited, targetCity, routeChanged);
        return routeChanged;
    }

    int bfsMode(vector<vector<int>> &forwardList, vector<vector<int>> &backwardList, int targetCity)
    {
        queue<int> q;
        vector<bool> visited(forwardList.size(), false);
        q.push(targetCity);
        visited[targetCity] = true;

        int routeChange = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto neighbour : forwardList[curr])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                    routeChange++;
                }
            }

            for (auto neighbour : backwardList[curr])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return routeChange;
    }

    void dfsMode(vector<vector<int>> &forwardList, vector<vector<int>> &backwardList, vector<bool> &visited, int targetCity, int &routeChanged)
    {
        visited[targetCity] = true;

        for (auto neighbour : forwardList[targetCity])
        {
            if (!visited[neighbour])
            {
                dfsMode(forwardList, backwardList, visited, neighbour, ++routeChanged);
            }
        }

        for (auto neighbour : backwardList[targetCity])
        {
            if (!visited[neighbour])
            {
                dfsMode(forwardList, backwardList, visited, neighbour, routeChanged);
            }
        }
    }
};

#endif