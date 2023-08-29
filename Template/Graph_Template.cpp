#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    
    void dfsHelper(int node, bool *visited)
    {
        visited[node] = true;
        cout << node << ' ';

        // make a dfs call on all its unvisited neighbours
        for (int nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
        return;
    }

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void dfs(int source)
    {
        bool *visited = new bool[V]{0};
        dfsHelper(source, visited);
        for (int i = 0; i < V; ++i) // For all the components
            if (visited[i] == 0)
                dfsHelper(i, visited);
        cout << '\n';
    }

    void bfs(int source)
    {

        queue<int> q;
        bool *visited = new bool[V]{0};

        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            // Do some work for every node
            int f = q.front();
            cout << f << ' ';
            q.pop();

            // PUsh the nbrs of current node inside q if they are not already visited
            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        cout << '\n';
    }
};
