#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 1010;

int inf = 1e9;
int mod = 1e9 + 7;

inline void add(int &a, int b)
{
   a += b;
   if (a >= mod)
      a -= mod;
}

inline void sub(int &a, int b)
{
   a -= b;
   if (a < 0)
      a += mod;
}

inline int mul(int a, int b)
{
   return (int)((long long)a * b % mod);
}

inline int power(int a, long long b)
{
   int res = 1;
   while (b > 0)
   {
      if (b & 1)
      {
         res = mul(res, a);
      }
      a = mul(a, a);
      b >>= 1;
   }
   return res;
}

inline int inv(int a)
{
   a %= mod;
   if (a < 0)
      a += mod;
   int b = mod, u = 0, v = 1;
   while (a)
   {
      int t = b / a;
      b -= t * a;
      swap(a, b);
      u -= t * v;
      swap(u, v);
   }
   assert(b == 1);
   if (u < 0)
      u += mod;
   return u;
}

int A[2 * N + 1][2 * N + 1];

void add(int x, int y, int c)
{
   x += N;
   y += N;
   if (c < 0)
      c += mod;
   A[x][y] = c;
}

int sum[2 * N][2 * N];
int tri[2 * N][2 * N];
int offset = N;

int get(int x1, int y1, int x2, int y2)
{
   int ans = sum[x2][y2];
   if (y1)
      sub(ans, sum[x2][y1 - 1]);
   if (x1)
      sub(ans, sum[x1 - 1][y2]);
   if (x1 && y1)
      add(ans, sum[x1 - 1][y1 - 1]);
   return ans;
}

void pre()
{
   for (int i = 0; i < 2 * N; i++)
   {
      for (int j = 0; j < 2 * N; j++)
      {
         sum[i][j] = A[i][j];
         if (i)
            add(sum[i][j], sum[i - 1][j]);
         if (j)
            add(sum[i][j], sum[i][j - 1]);
         if (i && j)
            sub(sum[i][j], sum[i - 1][j - 1]);
      }
   }

   for (int i = 0; i < 2 * N; i++)
   {
      for (int j = 0; j < 2 * N; j++)
      {
         tri[i][j] = 0;
         if (i && j)
            add(tri[i][j], tri[i - 1][j - 1]);
         add(tri[i][j], get(0, j, i, j));
      }
   }
   return;
}

signed main()
{
   // freopen("IN", "r", stdin);
   // freopen("OUT", "w", stdout);

   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n, m, q;
   cin >> n >> m >> q;

   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         int x;
         cin >> x;
         add(i, j, x);
      }
   }

   pre();

   while (q--)
   {
      int x, y, l;
      cin >> x >> y >> l;
      x += offset;
      y += offset;
      int ans = tri[x][y];
      int x1 = x - l;
      int y1 = y - l;
      sub(ans, tri[x1][y1]);
      sub(ans, get(0, y1 + 1, x1, y));
      cout << ans << "\n";
   }

   return 0;
}