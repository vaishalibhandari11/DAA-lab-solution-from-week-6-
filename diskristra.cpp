#include <bits/stdc++.h>
using namespace std;

void dijkstra(unordered_map<string, vector<pair<string, int>>> &graph, string source, string destination) {
    
    unordered_map<string, int> dist;
    unordered_map<string, string> parent;

    for (auto &node : graph) {
        dist[node.first] = INT_MAX;
    }

    dist[source] = 0;

    priority_queue<
        pair<int, string>, 
        vector<pair<int, string>>, 
        greater<pair<int, string>>
    > pq;

    pq.push({0, source});

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int currDist = current.first;
        string u = current.second;

        // ✅ Important fix
        if (currDist > dist[u]) continue;

        for (auto &neighbor : graph[u]) {
            string v = neighbor.first;
            int weight = neighbor.second;

            if (currDist + weight < dist[v]) {
                dist[v] = currDist + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // ✅ Check if reachable
    if (dist[destination] == INT_MAX) {
        cout << "\nNo path exists between " << source << " and " << destination << endl;
        return;
    }

    cout << "\nShortest Distance: " << dist[destination] << endl;

    // ✅ Safe path reconstruction
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
        graph[v].push_back({u, w});
    }

    string source, destination;
    cout << "Enter friend's location (source): ";
    cin >> source;

    cout << "Enter Akshay's house (destination): ";
    cin >> destination;

    dijkstra(graph, source, destination);

    return 0;
}