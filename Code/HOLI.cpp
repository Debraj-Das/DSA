#include <iostream>
#include <vector>
using namespace std;

#define ll long long

// Give us the size of the tree from the node where it is called
int dfs(int u, int parent, vector<pair<int, int>> adj[], ll &ans, int N)
{

    int currentTreeSize = 1;
    for (auto p : adj[u])
    {
        int v = p.first;
        int wt = p.second;
        // Skip the parent node (which is acting as nbr)
        if (v == parent)
        {
            continue;
        }
        int childTreeSize = dfs(v, u, adj, ans, N);
        int edgeContribution = 2 * min(childTreeSize, N - childTreeSize) * wt;
        ans += edgeContribution;
        // update the tree size by adding childTree Size
        currentTreeSize += childTreeSize;
    }
    return currentTreeSize;
}

int main()
{
    // your code goes here
    int test;
    cin >> test;
    int n, u, v, w;

    // Graph
    vector<pair<int, int>> adj[100005];
    int tc = 1;

    while (tc <= test)
    {
        cin >> n;
        // reset the adj list before every  test case
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        // scan the graph
        for (int i = 1; i <= n - 1; i++)
        {
            cin >> u >> v >> w;
            adj[u].push_back({v, w});   //* new impliment of Vector
            adj[v].push_back({u, w});
        }

        // dfs
        ll ans = 0;
        dfs(1, -1, adj, ans, n);
        cout << "Case #" << tc << ": " << ans << endl;
        tc = tc + 1;
    }

    return 0;
}
