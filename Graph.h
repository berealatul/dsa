#ifndef GRAPH
#define GRAPH

#include <vector>
using namespace std;

class Graph
{
public:
    // traverse given graph in form of adjacency list through dfs
    static void dfs(const vector<vector<int>> &adjList, vector<bool> &visited, const int start);

    // traverse given graph in form of adjacency list through bfs
    static void bfs(const vector<vector<int>> &adjList, vector<bool> &visited, const int start);

    // https://leetcode.com/problems/find-if-path-exists-in-graph
    // find if path from source to destination exist in an undirected graph. it can be disconnected
    static bool validPath(int n, vector<vector<int>> &edges, int source, int destination);
};

#endif