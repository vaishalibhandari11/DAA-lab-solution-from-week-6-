// Write a C++ program to implement Depth First Search (DFS) on a graph.
// The program should take the number of vertices and edges as input,
// construct the graph using an adjacency list, and determine whether
// a path exists between a given source and destination vertex.

#include <iostream>
#include <vector>
using namespace std;

// DFS function
bool dfs(int node, int dest, vector<vector<int>> &adj, vector<bool> &visited) {
    
    if (node == dest)
        return true;

    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, dest, adj, visited))
                return true;
        }
    }

    return false;
}

int main() {
    int V, E;
    
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // For undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);

        // For directed graph, use only:
        // adj[u].push_back(v);
    }

    int src, dest;
    cout << "Enter source vertex: ";
    cin >> src;

    cout << "Enter destination vertex: ";
    cin >> dest;

    vector<bool> visited(V, false);

    if (dfs(src, dest, adj, visited))
        cout << "Path exists\n";
    else
        cout << "Path does not exist\n";

    return 0;
}