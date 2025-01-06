void distance(int u)
{
    vis.assign(n, inf);
    vis[u] = 0;

    deque<int> q;
    q.push_back(u);
    while (q.size())
    {
        u = q.front();
        q.pop_front();

        for (auto &v : gr[u])
        {
            if (vis[v.ff] > vis[u] + v.ss)
            {
                vis[v.ff] = vis[u] + v.ss;

                if (v.ss)
                    q.push_back(v.ff);
                else
                    q.push_front(v.ff);
            }
        }
    }

    return;
}

/*
// Zero one Graph
int n, m;
V<V<pii>> gr;
vi vis;

void solve()
{
    cin >> n >> m;
    gr.resize(n, V<pii>(0));
    int u, v, w;

    f(i, 0, m)
    {
        cin >> u >> v >> w;
        u--, v--;
        gr[u].pb({v, w});
        gr[v].pb({u, w});
    }

    distance(0);

    f(i, 0, n)
    {
        cout << eif((vis[i] == inf), -1, vis[i]) << sp;
    }
    cout << el;

    return;
}


*/