#include <bits/stdc++.h>
using namespace std;
/*
* This is the Discription of the Unweight Graph Template
    V = Number of vertex
    adj = it is adjacency list of graph
    vertex = It is store the vertex of the graph and related the index of the vector
    m = it is related the vertex to the index of the array
    bidir = it is true then the graph is undirected otherwise directed
*/

template <typename T = int>
class Graph
{
private:
    int V;
    vector<int> *adj;
    T *vertex;
    unordered_map<T, int> m;
    bool bidir;

public:
    Graph(int V, T v[], bool bidir = true)
    {
        this->V = V;
        vertex = new T[V];
        adj = new vector<int>[V];
        for (int i = 0; i < V; i++)
        {
            vertex[i] = v[i];
            m[v[i]] = i;
        }
        this->bidir = bidir;
    }
    ~Graph()
    {
        delete[] vertex;
        delete[] adj;
    }

    // intialised the graph
    void addEdge(int, int);
    void addEdgeV(T, T);

    //  Traverse the graph
    void BFS(T);
    void DFS(T);

    // cycle detection
    bool isCyclic();


    // Topological Sort
    void TopologicalSort();
};

template <typename T>
void Graph<T>::addEdge(int u, int v)
{
    adj[u].push_back(v);
    if (bidir)
        adj[v].push_back(u);
}

template <typename T>
void Graph<T>::addEdgeV(T u, T v)
{
    adj[m[u]].push_back(m[v]);
    if (bidir)
        adj[m[v]].push_back(m[u]);
}








/*
    * How to use the template of the unweight graph

*/


int main()
{
    return 0;
}
