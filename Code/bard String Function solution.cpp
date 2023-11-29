#include <bits/stdc++.h>
using namespace std;

const char el = '\n';

inline void solve();

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   solve();

   return 0;
}

void solve()
{
   int n, q;
   cin >> n >> q;

   string s;
   cin >> s;

   while (q--)
   {
      string cmd;
      cin >> cmd;

      if (cmd == "substr")
      {
         int l, r;
         cin >> l >> r;
         cout << s.substr(l - 1, r - l + 1) << el;
      }
      else if (cmd == "sort")
      {
         int l, r;
         cin >> l >> r;
         sort(s.begin() + l - 1, s.begin() + r);
      }
      else if (cmd == "pop_back")
      {
         s.pop_back();
      }
      else if (cmd == "back")
      {
         cout << s.back() << el;
      }
      else if (cmd == "reverse")
      {
         int l, r;
         cin >> l >> r;
         reverse(s.begin() + l - 1, s.begin() + r);
      }
      else if (cmd == "front")
      {
         cout << s.front() << el;
      }
      else if (cmd == "print")
      {
         int pos;
         cin >> pos;
         cout << s[pos - 1] << el;
      }
      else if (cmd == "push_back")
      {
         char c;
         cin >> c;
         s.push_back(c);
      }
   }
}
