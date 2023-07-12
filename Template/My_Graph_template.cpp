#include <bits/stdc++.h>
using namespace std;

template <class T>
class Graph
{
private:
    int V = 0;
    list<int> *l = nullptr;
    vector<T> vertex;
    map<T, int> v_map; // if need for time complexity than used unorder_map

protected:
    void add_Index_Edge(int i, int j, bool undir = true)
    {
        if (i >= V or j >= V)
            return;
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }
    void dfs(int node, bool *visited)
    {
        visited[node] = true;
        cout << vertex[node] << ' ';
        for (int nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfs(nbr, visited);
            }
        }
        return;
    }

    void bfs(int source, bool visited[])
    {
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int node = q.front();
            cout << vertex[node] << ' ';
            q.pop();
            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

public:
    Graph(vector<T> arr)
    {
        V = arr.size();
        l = new list<int>[V];
        vertex.insert(vertex.end(), arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i)
            v_map[arr[i]] = i;
    }
    ~Graph()
    {
        delete[] l;
    }

    void addVertex(vector<T> arr)
    {
        V += arr.size();
        l->resize(V);
        vertex.insert(vertex.end(), arr.begin(), arr.end());
    }

    void addEdge(T s, T d, bool undir = true)
    {
        if (v_map.find(s) == v_map.end() or v_map.find(d) == v_map.end())
            return;
        int i = v_map[s], j = v_map[d];
        add_Index_Edge(i, j, undir);
        return;
    }

    void dfs(T s)
    {
        int source;
        if (v_map.find(s) == v_map.end())
            source = 0;
        else
            source = v_map[s];
        bool *visited = new bool[V]{0};
        dfs(source, visited);
        for (int i = 0; i < V; ++i)
            if (visited[i] == 0)
                dfs(i, visited);
        cout << '\n';
    }

    void bfs(T s)
    {
        int source;
        if (v_map.find(s) == v_map.end())
            source = 0;
        else
            source = v_map[s];
        bool *visited = new bool[V]{0};
        bfs(source, visited);
        for (int i = 0; i < V; ++i)
            if (visited[i] == 0)
                dfs(i, visited);

        cout << '\n';
        return;
    }

    void component()
    {
        int source = 0, component = 1;
        bool *visited = new bool[V]{0};
        for (int i = 0; i < V; ++i)
            if (visited[i] == 0)
            {
                cout << "Components " << component << " :\n\t";
                dfs(i, visited);
                cout<< '\n' ; 
                ++component;
            }
        return;
    }

    //* other algorithm define
};

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6};
    Graph<int> g(v);
    g.addEdge(1, 2);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    cout << "DFS of the graph : " << '\n';
    g.dfs(1);
    cout << "BFS of the graph : " << '\n';
    g.bfs(2);
    // g.component();

    return 0;
}
