/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

/*
 graph class
 Here I am assuming that the graph is undirected and unweighted
 I am assuming that vertex is 0 to v-1 (mapped to 0 to v-1)
*/

class graph
{
private:
    int v;
    vector<int> *adj;

protected:
    void DFSUtil(int, bool *);

public:
    graph(int v)
    {
        this->v = v;
        adj = new vector<int>[v];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
        return;
    }

    void print_graph()
    {
        f(i, 0, v)
        {
            cout<<i<<" : ";
            for (auto x : adj[i])
                cout << x << ' ';
            cout << el;
        }
    }

    // Depth search traversal and T(v+2e) and S(v)   e = no of edges and v = no of edges
    void DFS(int s = 0)
    {
        bool visited[v] = {false};
        DFSUtil(s, visited);
        f(i, 0, v) if (!visited[i]) DFSUtil(i, visited);
        return;
    }

    // Bearth search traversal and T(v+2e) and S(v)
    void BFS(int);

    // Small path between two source and distine
    // void smallestPath(int, int);
};

void graph::DFSUtil(int s, bool *arr)
{
    cout << s << " ";
    arr[s] = true;
    for (auto i : adj[s])
        if (!arr[i])
            DFSUtil(i, arr);
    return;
}

void graph::BFS(int s = 0)
{
    bool visited[v] = {false};
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        cout << s << ' ';
        for (auto i : adj[s])
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
    }
    return;
}


void solve()
{
    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.print_graph();

    g.DFS(3);
    cout << el;
    g.BFS(2);
    cout << el;

    return;
}