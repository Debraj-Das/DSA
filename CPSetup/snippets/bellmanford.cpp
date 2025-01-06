struct Edge {
   int u, v, w;
};

void solve() {
   int n, m;
   cin >> n >> m;

   vector<Edge> edges(m);
   for (Edge &e : edges) {
      cin >> e.u >> e.v >> e.w;
   }

   int src;
   cin >> src;

   vector<int> dist(n + 1, 1e9);
   dist[src] = 0;

   for (int i = 1; i < n; i++) {
      for (const Edge &e : edges) {
         dist[e.v] = min(dist[e.v], dist[e.u] + e.w);
         dist[e.u] = min(dist[e.u], dist[e.v] + e.w);
      }
   }

   for (const Edge &e : edges) {
      if (dist[e.v] > dist[e.u] + e.w) {
         cerr << "nagative cyclic present";
         return;
      }
   }

   for (int i = 1; i <= n; i++) {
      cout << dist[i] << sp;
   }

   return;
}
