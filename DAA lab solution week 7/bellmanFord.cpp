#include <bits/stdc++.h>
using namespace std;

void bellmanFord(unordered_map<string, vector<pair<string, int>>> &graph, string source, string destination) {
    
    unordered_map<string, int> dist;
    unordered_map<string, string> parent;

    // Initialize distances
    for (auto &node : graph) {
        dist[node.first] = INT_MAX;
    }

    dist[source] = 0;

    int V = graph.size();

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto &node : graph) {
            string u = node.first;

            for (auto &neighbor : graph[u]) {
                string v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycle
    for (auto &node : graph) {
        string u = node.first;

        for (auto &neighbor : graph[u]) {
            string v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle\n";
                return;
            }
        }
    }

    // If destination unreachable
    if (dist[destination] == INT_MAX) {
        cout << "\nNo path exists between " << source << " and " << destination << endl;
        return;
    }

    // Print result
    cout << "\nShortest Distance: " << dist[destination] << endl;

    // Reconstruct path
    vector<string> path;
    string current = destination;

    while (current != source) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(source);

    reverse(path.begin(), path.end());

    cout << "Shortest Path: ";
    for (auto &node : path) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    unordered_map<string, vector<pair<string, int>>> graph;

    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node names:\n";
    for (int i = 0; i < n; i++) {
        string node;
        cin >> node;
        graph[node] = {};
    }

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // remove if directed
    }

    string source, destination;
    cout << "Enter friend's location (source): ";
    cin >> source;

    cout << "Enter Akshay's house (destination): ";
    cin >> destination;

    bellmanFord(graph, source, destination);

    return 0;
}