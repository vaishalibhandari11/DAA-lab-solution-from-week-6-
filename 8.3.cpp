//krushkal
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

struct Edge {
    int u, v, w;
};

Edge edges[MAX * MAX];
int parent[MAX];
int edgeCount = 0;
int V;

int findParent(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unionSet(int a, int b) {
    parent[findParent(a)] = findParent(b);
}

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int kruskalMST() {
    for (int i = 0; i < V; i++)
        parent[i] = i;

    sort(edges, edges + edgeCount, compare);

    int totalWeight = 0;
    int selected = 0;

    for (int i = 0; i < edgeCount && selected < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findParent(u) != findParent(v)) {
            unionSet(u, v);
            totalWeight += edges[i].w;
            selected++;
        }
    }

    return totalWeight;
}

int main() {
    int graph[MAX][MAX];
    cin >> V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];

            if (graph[i][j] > 0 && i < j) {
                edges[edgeCount++] = {i, j, graph[i][j]};
            }
        }
    }

    cout << "Minimum Spanning Weight: " << kruskalMST();

    return 0;
}