#ifndef GRAPH
#define GRAPH

#include <vector>
using namespace std;

class Graph
{
public:
    // traverse given graph in form of adjacency list through dfs
    static void dfs(vector<vector<int>> &adjList, vector<bool> &visited, int start);

    // traverse given graph in form of adjacency list through bfs
    static void bfs(vector<vector<int>> &adjList, vector<bool> &visited, int start);
};

#endif