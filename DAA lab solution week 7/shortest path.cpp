#include <bits/stdc++.h>
using namespace std;

void shortestPathK(
    unordered_map<string, vector<pair<string,int>>> &graph,
    vector<string> &nodes,
    string source,
    string destination,
    int k
) {
    int V = nodes.size();

    // Map node name → index
    unordered_map<string, int> index;
    for (int i = 0; i < V; i++) {
        index[nodes[i]] = i;
    }

    // dp[e][v] = shortest distance to reach v using exactly e edges
    vector<vector<int>> dp(k + 1, vector<int>(V, INT_MAX));

    dp[0][index[source]] = 0;

    // DP computation
    for (int e = 1; e <= k; e++) {
        for (auto &node : graph) {
            string u = node.first;

            if (dp[e - 1][index[u]] == INT_MAX) continue;

            for (auto &nbr : graph[u]) {
                string v = nbr.first;
                int w = nbr.second;

                dp[e][index[v]] = min(dp[e][index[v]],
                                     dp[e - 1][index[u]] + w);
            }
        }
    }

    // Output
    if (dp[k][index[destination]] == INT_MAX) {
        cout << "no path of length k is available";
    } else {
        cout << "Shortest weight with exactly " << k << " edges: "
             << dp[k][index[destination]];
    }
}

int main() {
    unordered_map<string, vector<pair<string,int>>> graph;

    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<string> nodes(n);

    cout << "Enter node names:\n";
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
        graph[nodes[i]] = {};
    }

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w}); // directed graph
    }

    string source, destination;
    cout << "Enter source and destination: ";
    cin >> source >> destination;

    int k;
    cout << "Enter k (exact edges): ";
    cin >> k;

    shortestPathK(graph, nodes, source, destination, k);

    return 0;
}