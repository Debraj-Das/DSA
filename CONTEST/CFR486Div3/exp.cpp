#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int main()
{

   long long n;
   cin >> n;

   string s = to_string(n);

   int ans = INF;

   int len = s.size();
   for (int i = 0; i < len; ++i)
   {
      for (int j = 0; j < len; ++j)
      {
         if (i == j)
            continue;
         string t = s;
         int cur = 0;
         for (int k = i; k < len - 1; ++k)
         {
            swap(t[k], t[k + 1]);
            ++cur;
         }

         for (int k = j - (j > i); k < len - 2; ++k)
         {
            swap(t[k], t[k + 1]);
            ++cur;
         }

         int pos = -1;
         for (int k = 0; k < len; ++k)
         {
            if (t[k] != '0')
            {
               pos = k;
               break;
            }
         }

         for (int k = pos; k > 0; --k)
         {
            swap(t[k], t[k - 1]);
            ++cur;
         }

         long long nn = atoll(t.c_str());
         if (nn % 25 == 0)
            ans = min(ans, cur);
      }
   }

   if (ans == INF)
      ans = -1;

   cout << ans << endl;

   return 0;
}