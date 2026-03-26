// Given a directed graph, check whether a cycle exists or not using DFS.
// Output "Yes Cycle Exists" if cycle exists, otherwise "No Cycle Exists".

#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack) {
    
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }

    recStack[node] = false;
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); // directed graph
    }

    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    bool hasCycle = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        cout << "Yes Cycle Exists\n";
    else
        cout << "No Cycle Exists\n";

    return 0;
}