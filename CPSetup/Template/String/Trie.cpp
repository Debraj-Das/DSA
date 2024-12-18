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

struct node {
   node *child[26];
   int prefix;
   int cnt;
   string end;
   node() {
      prefix = 0;
      cnt = 0;
      for (int i = 0; i < 26; i++) {
         child[i] = nullptr;
      }
   }
};

struct tries {
   node *root;
   tries() { root = new node; }
   void insert(string s) {
      node *cur = root;
      const int n = s.size();
      for (int i = 0; i < n; i++) {
         cur->prefix++;
         int x = s[i] - 'a';
         if (cur->child[x] == nullptr) {
            cur->child[x] = new node;
         }
         cur = cur->child[x];
      }
      cur->cnt++;
      cur->end = s;
   }

   void find(node *cur, int &k, vector<string> &ans) {
      if (k == 0 or cur == nullptr) return;
      for (int i = 0; i < cur->cnt; i++) {
         ans.push_back(cur->end);
         k--;
         if (k == 0) return;
      }
      if (cur->prefix == 0) return;
      for (int i = 0; i < 26 and k > 0; i++) {
         find(cur->child[i], k, ans);
      }
   }

   vector<string> search(string s, int k) {
      node *cur = root;
      const int n = s.size();
      for (int i = 0; i < n; i++) {
         int x = s[i] - 'a';
         if (cur->child[x] == nullptr) {
            return {};
         }
         cur = cur->child[x];
      }
      vector<string> ans;
      find(cur, k, ans);
      return ans;
   }
};

void solve() {
   int n;
   cin >> n;
   string s;
   tries t;
   for (int i = 0; i < n; i++) {
      cin >> s;
      t.insert(s);
   }

   int q;
   cin >> q;
   for (int i = 0, k; i < q; i++) {
      cin >> s >> k;
      vector<string> ans = t.search(s, k);
      for (const string &e : ans) {
         cout << e << el;
      }
   }

   return;
}
