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
        return bfsMode(forwardList, backwardList, targetCity);
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
};

#endif