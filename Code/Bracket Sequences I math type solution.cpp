// Problem: Bracket Sequences I
// URL: https://cses.fi/problemset/task/2064
// Memory Limit: 512 MB
// Time Limit: 1000 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';
const int mod = 1e9 + 7;
const int inf = INT_MAX;
// const ld ep = 0.0000001;
// const ld pi = acos(-1.0);

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rev(i, a, b) for (int i = (a); i > (b); --i)
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define setpr(x) cout << setprecision(x) << fixed
#define sz size()

using pii = pair<int, int>;
#define ff first
#define ss second
#define mp make_pair

using vb = vector<bool>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()

template <typename T1, typename T2> using P = pair<T1, T2>;
template <typename T> using V = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;

template <typename T> inline T exp(T a, int b)
{
   T x = 1;
   while (b)
   {
      if (b & 1)
         x *= a;
      a *= a;
      b >>= 1;
   }
   return x;
}

// clang-format off
#ifndef ONLINE_JUDGE
#define prarr(a,n)std::cerr<<#a<<" : [ ";for(int i=0;i<n;i++)std::cerr<<a[i]<<' ';std::cerr<<"]\n";
#define prmat(mat,row,col)std::cerr<<#mat<<" :\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)std::cerr<<mat[i][j]<<' ';std::cerr<<'\n';}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class T>void dbs(string str,T t){cerr<<str<<": "<<t<<"\n";}
template<class T,class...S>void dbs(string str,T t,S... s){int idx=str.find(',');cerr<<str.substr(0,idx)<<": "<<t<<",";dbs(str.substr(idx+1),s...);}
#define prstl(x) std::cerr << #x<<" : "; _p(x); std::cerr << endl;
void _p(auto t) {std::cerr << t;}
template <class T, class V> void _p(std::pair <T, V> p) {std::cerr << "{ "; _p(p.first); std::cerr << ", "; _p(p.second); std::cerr << " }";}
template <class T> void _p(std::vector <T> v) {std::cerr << "[ "; for (const auto &i : v) {_p(i); std::cerr << " ";} std::cerr << "]";}
template <class T> void _p(std::set <T> v) {std::cerr << "[ "; for (const auto &i : v) {_p(i); std::cerr << " ";} std::cerr << "]";}
template <class T> void _p(std::multiset <T> v) {std::cerr << "[ "; for (const auto &i: v) {_p(i); std::cerr << " ";} std::cerr << "]";}
template <class T, class V> void _p(std::map <T, V> v) {std::cerr << "[ "; for (const auto &i : v) {_p(i); std::cerr << " ";} std::cerr << "]";}
template <class T, class V> void _p(std::unordered_map <T, V> v) {std::cerr << "[ "; for (const auto &i : v) {_p(i); std::cerr << " ";} std::cerr << "]";}
#else
#define pr(...){}
#define prarr(a,n){}
#define prmat(mat,row,col){}
#define prstl(x){}
#endif
// clang-format on

inline void solve();

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   // int __t ; cin >> __t; while (__t--)
   solve();

   return 0;
}

int fac(int n)
{
   int ans = 1;
   rep(i, 2, n + 1) ans = (ans * i) % mod;

   // pr(ans);
   return ans;
}

int inv(int a)
{
   int b = mod - 2, ans = 1;

   while (b)
   {
      if (b & 1)
         ans = (ans * a) % mod;
      a = (a * a) % mod;
      b >>= 1;
   }

   return ans;
}

void solve()
{
   int n;
   cin >> n;

   if (n & 1)
   {
      cout << 0;
      return;
   }

   n /= 2;

   cout << (fac(2 * n) * inv((fac(n + 1) * fac(n)) % mod)) % mod;

   return;
}
