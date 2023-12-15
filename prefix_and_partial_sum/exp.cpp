#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int arr[N];
int prefixSum[N];

signed main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n, k, q;
   cin >> n >> k >> q;

   for (int i = 0; i < N; i++)
      arr[i] = 0;
   for (int i = 1; i <= n; i++)
   {
      int l, r;
      cin >> l >> r;
      arr[l]++;
      arr[r + 1]--;
   }

   for (int i = 1; i < N; i++)
      arr[i] += arr[i - 1];
   for (int i = 1; i < N; i++)
      arr[i] = (arr[i] >= k);

   prefixSum[0] = 0;
   for (int i = 1; i < N; i++)
   {
      prefixSum[i] = prefixSum[i - 1] + arr[i];
   }

   while (q--)
   {
      int l, r;
      cin >> l >> r;
      int ans = prefixSum[r] - prefixSum[l - 1];
      cout << ans << "\n";
   }
}