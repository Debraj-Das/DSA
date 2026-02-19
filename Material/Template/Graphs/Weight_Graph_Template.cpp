#include <bits/stdc++.h>

using namespace std;

/*
   * This Discription for the weigh Graph Template
    V = Number of vertex
    adj = it is adjacency list of graph
    vertex = It is store the vertex of the graph and related the index of the vector
    m = it is related the vertex to the index of the array
    bidir = it is true then the graph is undirected otherwise directed

*/
template <typename T>
class Graph
{
    int V;
    vector<pair<int, int>> *adj;
    T *vertex;
    unordered_map<T, int> m;
    bool bidir;

public:
    Graph(int V, T v[], bool bidir = true)
    {
        this->V = V;
        vertex = new T[V];
        for (int i = 0; i < V; i++)
        {
            vertex[i] = v[i];
            m[v[i]] = i;
        }
        adj = new vector<pair<int, int>>[V];
        this->bidir = bidir;
    }

    ~Graph()
    {
        delete[] vertex;
        delete[] adj;
    }

    // intialised the graph
    void addEdge_vertex(T, T, int);
    void addEdge(int, int, int);

    //  Traverse the graph
    void BFS(T);
    void DFS(T);

    // cycle detection
    bool isCyclic();

    // Topological Sort
    void TopologicalSort();

    // minimum spanning tree
    void Prims();
    void Kruskal();

    // shortest path for given source
    void Dijkstra(T);
    void BellmanFord(T);

    // shortest path for all pair
    void FloydWarshall();

    // check the graph is bipartite or not

};

template <typename T>
void Graph<T>::addEdge_vertex(T u, T v, int w)
{
    adj[m[u]].push_back({m[v], w});
    if (bidir)
        adj[m[v]].push_back({m[u], w});
}

template <typename T>
void Graph<T>::addEdge(int u, int v, int w)
{
    adj[u].push_back({v, w});
    if (bidir)
        adj[v].push_back({u, w});
}
