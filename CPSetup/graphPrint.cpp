   for (int i = 0; i < n; i++)
   {
      cerr << (i + 1) << ": ";
      for (int v : gr[i])
         cerr << (v + 1) << sp;
      cerr << el;
   }