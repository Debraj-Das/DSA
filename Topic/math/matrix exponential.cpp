/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';
// const int mod = 1e9 + 7;
// const int inf = INT_MAX;
// const ld ep = 0.0000001;
// const ld pi = acos(-1.0);

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rev(i, a, b) for (int i = (a); i > (b); --i)
#define eif(cds, a, b) ((cds) ? (a) : (b))
#define setpr(x) cout << setprecision(x) << fixed

inline void solve();

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   int TC = 1;
   // cin >> TC;
   for (int i = 0; i < TC; i++)
   {
      // cout<<"case "<<(i+1)<<": ";
      solve();
      cout << '\n';
   }

   return 0;
}

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

void solve()
{
   cout << fib(5);

   return;
}
