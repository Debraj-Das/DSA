struct DSU
{
   int n, num_grp;
   int *par, *sz;

   DSU()
   {
      n = 0;
      num_grp = 0;
      par = NULL;
      sz = NULL;
   }

   DSU(int n)
   {
      this->n = n;
      num_grp = n;
      par = new int[n];
      sz = new int[n];
      for (int i = 0; i < n; i++)
      {
         par[i] = i;
         sz[i] = 1;
      }
   }

   void reset(int n = 0)
   {
      if (par)
         delete[] par;
      if (sz)
         delete[] sz;

      this->n = n;
      num_grp = n;

      if (n == 0)
      {
         par = NULL;
         sz = NULL;
         return;
      }

      par = new int[n];
      sz = new int[n];
      for (int i = 0; i < n; i++)
      {
         par[i] = i;
         sz[i] = 1;
      }
   }

   ~DSU()
   {
      if (par)
         delete[] par;
      if (sz)
         delete[] sz;
   }

   int find(int u)
   {
      return u == par[u] ? u : par[u] = find(par[u]);
   }

   void merge(int u, int v)
   {
      u = find(u), v = find(v);
      if (u == v)
         return;

      if (sz[u] > sz[v])
         swap(u, v);
      par[u] = v;
      sz[v] += sz[u];
      num_grp--;
   }

   int component()
   {
      return num_grp;
   }

   int sz_component(int u)
   {
      u = find(u);
      return sz[u];
   }
};


/*
// eg.   kruskal Algorithm(MST)
 
   int n, m;
   cin >> n >> m;

   array<int, 3> edgeList[m];
   for (int i = 0, u, v, w; i < m; i++)
   {
      cin >> u >> v >> w;
      edgeList[i][0] = w;
      edgeList[i][1] = u - 1;
      edgeList[i][2] = v - 1;
   }

   sort(edgeList, edgeList + m);

   int price = 0, edge = 0;
   DSU uf(n);
   F(&e, edgeList)
   {
      if (uf.find(e[1]) == uf.find(e[2]))
         continue;

      uf.merge(e[1], e[2]);
      price += e[0];
      edge++;
   }
   
   if(edge == (n-1))
   cout << price << el;
   else
   cout<<"NO Solution"<<el; // MST not possible

*/