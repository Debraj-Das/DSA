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

inline void solve();

int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   int TC = 1;
   // cin >> TC;
   for (int i = 0; i < TC; i++) {
      // cout<<"case "<<(i+1)<<": ";
      solve();
      cout << '\n';
   }

   return 0;
}

// struct defination for the solutions
struct complexm {
   int x, y;

   complexm(int x = 0, int y = 0) {
      this->x = x;
      this->y = y;
   }

   void view() {
      cerr << x << sp << "i" << y << el;
      return;
   }

   double mod() { return sqrt(x * x + y * y); }
};

void solve() {
   complexm num(3, 4);

   num.view();

   cerr << num.mod();

   return;
}
