using matrix = vector<vector<int>>;
matrix mulx(matrix &a, matrix &b)
{
   assert(a[0].size() == b.size());
   if (a[0].size() != b.size())
      return {{}};

   int n = a[0].size();
   int row = a.size(), col = b[0].size();

   matrix c(row, vector<int>(col, 0));
   for (int i = 0, j, k; i < row; i++)
      for (j = 0; j < col; j++)
         for (k = 0; k < n; k++)
            c[i][j] += a[i][k] * b[k][j];

   return c;
}

matrix expx(matrix &a, int b)
{
   assert(a.size() == a[0].size());

   int n = a.size();
   matrix ans(n, vector<int>(n, 0));
   for (int i = 0; i < n; i++)
      ans[i][i] = 1;

   while (b)
   {
      if (b & 1)
         ans = mulx(ans, a);
      a = mulx(a, a);
      b >>= 1;
   }

   return ans;
}

/*
   Assumsed Recurrence relationShip :
   fib(n) = fib(n-1) + 2*fib(n-3) + 2*n^2 + 3
   
** find the Fib(n-1), Fib(n) and A matrix
   Fib(n-1) = [fib(n-1), fib(n-2) , fib(n-3), n^2, n , 1];
   Fib(n) = [fib(n), fib(n-1), fib(n-2) , (n+1)^2, (n+1), 1];
   A = [ [1,0,2,2,0,3], 
         [1,0,0,0,0,0],
         [0,1,0,0,0,0], 
         [0,0,0,1,2,1],
         [0,0,0,0,1,1], 
         [0,0,0,0,0,1] ];
   
** check that relation hold  
   Fib(n) = A*Fib(n-1);
   
   finding the base value of recurrence
   and at base value n = k (order of recurrence)
   here k = 3
*/
int fib(int n)
{
   // Fib(n) = A*Fib(n-1)
   matrix A = {{1, 1}, {1, 0}};
   // base value of recurrence
   vector<int> base = {1, 1};
   // order the recurrence
   int k = 2;

   matrix a = expx(A, n - k + 1);
   int ans = 0;
   for (int i = 0; i < base.size(); i++)
      ans += a[0][i] * base[i];

   return ans;
}
