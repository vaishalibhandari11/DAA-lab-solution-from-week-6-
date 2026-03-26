// Write a C++ program to represent an undirected graph using an adjacency list.
// The program should take the number of vertices and edges as input,
// allow the user to enter edges, and then display the adjacency list.

#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u); // remove for directed graph
}

void printGraph(vector<vector<int>> &graph, int V)
{
    cout << "Adjacency List:\n";

    for(int i = 0; i < V; i++)
    {
        cout << i << " -> ";

        for(int j : graph[i])
        {
            cout << j << " ";
        }

        cout << endl;
    }
}

int main()
{
    int V,E;

    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V);

    cout << "Enter number of edges: ";
    cin >> E;

    for(int i = 0; i < E; i++)
    {
        int u,v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;

        addEdge(graph,u,v);
    }

    printGraph(graph,V);

    return 0;
}