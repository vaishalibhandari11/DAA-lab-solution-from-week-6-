#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

int graph[MAX][MAX];
int key[MAX];
bool mstSet[MAX];
int V;

int primMST() {
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    int totalWeight = 0;

    for (int count = 0; count < V; count++) {
        int u = -1;
        int minVal = INF;

        // Find minimum key
        for (int i = 0; i < V; i++) {
            if (!mstSet[i] && key[i] < minVal) {
                minVal = key[i];
                u = i;
            }
        }

        if (u == -1) break;

        mstSet[u] = true;
        totalWeight += key[u];

        // Update adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] > 0 && !mstSet[v] &&
                graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    cin >> V;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    cout << "Minimum Spanning Weight: " << primMST();

    return 0;
}