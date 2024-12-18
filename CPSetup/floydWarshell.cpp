int n, m;
   cin >> n >> m;

   int dist[n][n];
   for (int i = 0, j; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         dist[i][j] = eif((i == j), 0, inf);
      }
   }

   for (int i = 0, u, v, w; i < m; i++)
   {
      cin >> u >> v >> w;
      u--, v--;
      dist[u][v] = w;
   }

   // floyd warshall algorithm
   for (int k = 0, i, j; k < n; k++)
      for (i = 0; i < n; i++)
         for (j = 0; j < n; j++)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
   
   // You got any pair of shortest path dist[i][j] == shortest path between i to j or j to i
