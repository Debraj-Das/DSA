void distance(int u)
{
    vis.assign(n, inf);
    vis[u] = 0;

    queue<int> q;
    q.push(u);
    while (q.size())
    {
        u = q.front();
        q.pop();

        for (auto &v : gr[u])
        {
            if (vis[v] > vis[u] + 1)
            {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }

    return;
}

void multisourceDistance(vi source)
{
    vis.assign(n, inf);
    queue<int> q;
    for (auto &u : source)
    {
        vis[u] = 0;
        q.push(u);
    }

    int u;
    while (q.size())
    {
        u = q.front();
        q.pop();

        for (auto &v : gr[u])
        {
            if (vis[v] > vis[u] + 1)
            {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }

    return;
}

/*
int n, m;
V<vi> gr;
vi vis;

void solve()
{
    cin >> n >> m;
    gr.resize(n, vi(0));
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;

        gr[u].pb(v);
        gr[v].pb(u);
    }

    multisourceDistance({0});

    f(i, 0, n)
    {
        cout << eif((vis[i] == inf), -1, vis[i]) << sp;
    }
    cout << el;

    return;
}


*/