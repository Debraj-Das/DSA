#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

long long solve(vector<int> &A, int l, int r)
{
   if (l > r)
      return 0;
   if (l == r)
      return 0;
   if (r - l == 1)
   {
      if (A[r] < A[l])
      {
         swap(A[r], A[l]);
         return 1;
      }
      return 0;
   }

   int mid = (l + r) / 2;

   long long ans = solve(A, l, mid) + solve(A, mid + 1, r);

   int ptr = mid + 1;
   for (int i = l; i <= mid; i++)
   {
      while (ptr <= r && A[ptr] < A[i])
         ptr++;
      ans += 1LL * (ptr - mid - 1);
   }
   vector<int> temp;
   for (int i = l; i <= r; i++)
      temp.push_back(A[i]);
   sort(temp.begin(), temp.end());
   for (int i = l; i <= r; i++)
      A[i] = temp[i - l];
   return ans;
}

signed main()
{
   // freopen("IN", "r", stdin);
   // freopen("OUT", "w", stdout);

   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int T;
   cin >> T;
   while (T--)
   {
      int n;
      cin >> n;
      vector<int> A(n);
      for (int i = 0; i < n; i++)
         cin >> A[i];
      cout << solve(A, 0, n - 1) % 2 << "\n";
   }
   return 0;
}