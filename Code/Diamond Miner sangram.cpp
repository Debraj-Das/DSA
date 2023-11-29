#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1)
{
   std::cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args> void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
   const char *comma = strchr(names + 1, ',');
   std::cerr.write(names, comma - names) << " : " << arg1 << '\n';
   __f(comma + 1, args...);
}

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l = 0, int r = 1e9)
{
   return std::uniform_int_distribution<int>(l, r)(rng);
}

#define time(n)                                                                                                        \
   clock_t tt = clock();                                                                                               \
   while ((double)(clock() - tt) / CLOCKS_PER_SEC < n)

#define ll long long
#define el '\n'
#define sp ' '

#define f(i, a, b) for (int i = a; i < (b); i++)
#define fr(i, a, b) for (int i = a; i >= (b); i--)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define maxa(a, b) a += ((b)-a) * ((b) > a)
#define mina(a, b) a -= (a - (b)) * ((b) < a)

#define all(a) a.begin(), a.end()
#define F(x, a) for (auto x : a)

#define pii pair<int, int>
#define ff first
#define ss second
#define mp make_pair

#define vi vector<int>
#define pb push_back

template <typename T> using V = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;

inline int exp(int a, int b)
{
   int x;
   for (x = 1; b; a *= a, b >>= 1)
      x *= (a * (b & 1) + !(b & 1));
   return x;
}

inline void solve();

double squareRoot(int number, int precision)
{
   int start = 0, end = number;
   int mid;

   double ans;

   while (start <= end)
   {
      mid = (start + end) / 2;
      if (mid * mid == number)
      {
         ans = mid;
         break;
      }

      if (mid * mid < number)
      {
         start = mid + 1;
         ans = mid;
      }
      else
      {
         end = mid - 1;
      }
   }

   double increment = 0.1;
   for (int i = 0; i < precision; i++)
   {
      while (ans * ans <= number)
      {
         ans += increment;
      }

      // loop terminates when ans * ans > number
      ans = ans - increment;
      increment = increment / 10;
   }
   return ans;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   int t;
   cin >> t;
   while (t--)
      solve();

   return 0;
}

void solve()
{
   int n;
   cin >> n;

   int x[n], y[n], z, z1, x1 = 0, y1 = 0;

   f(i, 0, 2 * n)
   {
      cin >> z >> z1;

      if (z == 0)
      {
         y[y1] = abs(z1);
         y1++;
      }
      else
      {
         x[x1] = abs(z);
         x1++;
      }
   }

   sort(x, x + n);
   sort(y, y + n);

   double sum = 0;

   f(i, 0, n)
   {
      sum += sqrt((1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]));
   }

   std::cout << std::fixed << std::setprecision(15);
   cout << sum << endl;
   return;
}