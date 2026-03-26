// Write a C++ program to represent an undirected graph using an adjacency matrix.
// The program should take the number of vertices and edges as input,
// allow the user to enter edges, and then display the adjacency matrix.

#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1; // remove for directed graph
}

void printGraph(vector<vector<int>> &graph, int V)
{
    cout << "Adjacency Matrix:\n";
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int V, E;
    
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V,0));

    cout << "Enter number of edges: ";
    cin >> E;

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;

        addEdge(graph,u,v);
    }

    printGraph(graph,V);

    return 0;
}