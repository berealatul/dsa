#ifndef STEPS_BY_KNIGHT
#define STEPS_BY_KNIGHT

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        KnightPos[0]--;
        KnightPos[1]--;
        TargetPos[0]--;
        TargetPos[1]--;

        vector<vector<bool>> visited(N, vector<bool>(N, false));
        return bfsMode(KnightPos, TargetPos, visited, N);
    }

private:
    int bfsMode(vector<int> source, vector<int> destination, vector<vector<bool>> &visited, int totalNodes)
    {
        queue<vector<int>> q;
        q.push(source);
        visited[source[0]][source[1]] = true;

        vector<vector<int>> directions = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
        int minSteps = 0;

        while (!q.empty())
        {
            for (int i = 0, n = q.size(); i < n; i++)
            {
                int x = q.front()[0];
                int y = q.front()[1];
                q.pop();

                if (x == destination[0] && y == destination[1])
                    return minSteps;

                for (auto direction : directions)
                {
                    int newX = direction[0] + x;
                    int newY = direction[1] + y;

                    if (newX >= 0 && newX < totalNodes && newY >= 0 && newY < totalNodes && !visited[newX][newY])
                    {
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }

            minSteps++;
        }

        return minSteps;
    }
};

#endif
