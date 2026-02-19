void dijstra(int sc)
{
    vis.assign(n, 0);
    dist.assign(n, inf);

    dist[sc] = 0;
    pqg<pii> p;
    p.push(mp(0, sc));

    pii fs;
    int neigh, wg;
    while (p.size())
    {
        fs = p.top();
        p.pop();

        if (vis[fs.ss])
            continue;
        vis[fs.ss] = 1;

        for (auto &v : gr[fs.ss])
        {
            neigh = v.ff;
            wg = v.ss;
            if (dist[neigh] > dist[fs.ss] + wg)
            {
                dist[neigh] = dist[fs.ss] + wg;
                p.push(mp(dist[neigh], neigh));
            }
        }
    }

    return;
}

/*
int n, m;
V<V<pii>> gr;
vi vis;
vi dist;

void solve()
{
    cin >> n >> m;
    gr.resize(n, V<pii>(0));
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        u--, v--;
        gr[u].pb({v, w});
        gr[v].pb({u, w});
    }

    int sc;
    cin >> sc;
    dijstra(sc - 1);

    f(i, 0, n) cout << dist[i] << sp;
    cout << el;

    return;
}


*/