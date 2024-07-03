#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const ll INF = 1ll*mod*mod;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
#define setpr(x) cout << setprecision(x) << fixed

// clang-format off
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline int rdi(int l = 0, int r = 1e9){ return std::uniform_int_distribution<int>(l, r)(rng); }
// clang-format on

inline double rdd(int l = 0 , int r = 100000){
	double ans = rdi(1000 , 1000*r);
	return ans /1000 ;
}

// shuffle(v.begin(), v.end(), rng);  // shuffle syntex

const string a =  "abcdefghijklmnopqrstuvwxyz";
const string A =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string num = "0123456789";
const string spec = "!@#$%^&*";

inline char rdc(){
	const string source = a ;
	const int n = source.size() - 1;

	return source[rdi(0,n)];
}

void text(int len){
	const string source = a + A + num + spec;
	const int n = source.size() - 1 ;

   while(len--) {
      cout << source[rdi(0, n)];
   }
   cout << el;
   return;
}

void arr(const int n, const int l = 0, const int r = 1e9){
   cout << n << el;
   for (int i = 0; i < n; i++){
      cout << rdi(l, r) << sp;
   }
   cout << el;
   return;
}

void distinctElements(const int n,const int l = 0,const int r = 1e9){
   cout << n << el;

   set<int> used;
   for (int i = 0, x; i < n; i++){
      do{
         x = rdi(l, r);
      }while (used.count(x));

      cout << x << sp;
      used.insert(x);
   }
   cout << el;
   return;
}

void tree(int n){
   cout << n << el;

   vector<pair<int, int>> edges;
   for (int i = 2; i <= n; ++i){
      edges.emplace_back(rdi(1, i - 1), i);
   }

   random_shuffle(edges.begin(), edges.end());
   for (pair<int, int> &e : edges){
      if (rdi() % 2){
         swap(e.first, e.second);
      }
      cout << e.first << sp << e.second << el;
   }
   return;
}

inline void graph(const int n,int e) {
	cout<<n<<sp<<e<<el;

	set<pair<int,int>> st;
   int u, v;
	while(e--){
		u = rdi(1,n-1) ;
		do{
			v = rdi(u,n);
		}while(st.find(make_pair(u,v)) != st.end());
		
		st.insert(make_pair(u,v));

		if(rdi()%2){
			swap(u,v);
      }
		cout<<u<<sp<<v<<el;
	}
	return ;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);


   return 0;
}

