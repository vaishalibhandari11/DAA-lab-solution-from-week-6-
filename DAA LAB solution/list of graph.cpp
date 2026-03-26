// Write a C++ program to represent an undirected graph using an adjacency list
// where vertices are represented as strings (e.g., city names).
// The program should take connections between cities as input
// and display the adjacency list of the graph.

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void addEdge(map<string, vector<string>> &graph, string u, string v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph(map<string, vector<string>> &graph)
{
    cout << "Adjacency List:\n";

    for(auto city : graph)
    {
        cout << city.first << " -> ";

        for(auto neighbour : city.second)
        {
            cout << neighbour << " ";
        }

        cout << endl;
    }
}

int main()
{
    int E;

    map<string, vector<string>> graph;

    cout << "Enter number of edges: ";
    cin >> E;

    for(int i = 0; i < E; i++)
    {
        string u,v;

        cout << "Enter connection (city1 city2): ";
        cin >> u >> v;

        addEdge(graph,u,v);
    }

    printGraph(graph);

    return 0;
}