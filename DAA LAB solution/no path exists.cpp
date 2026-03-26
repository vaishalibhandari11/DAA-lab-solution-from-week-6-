// Given a graph, design an algorithm and implement it using a program
// to find if a path exists between two given vertices using DFS.
// Input is provided as an adjacency list along with source and destination.
// Output "Yes Path Exists" if path exists, otherwise print "No Such Path Exists".

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

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src, dest;
    cout << "Enter source vertex: ";
    cin >> src;

    cout << "Enter destination vertex: ";
    cin >> dest;

    vector<bool> visited(V, false);

    if (dfs(src, dest, adj, visited))
        cout << "Yes Path Exists\n";
    else
        cout << "No Such Path Exists\n";

    return 0;
}