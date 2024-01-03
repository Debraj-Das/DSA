// Problem: Y. Polo the Penguin and Segments
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/Y
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/
#include <cstdio>

int main()
{
   int n, k, ans = 0;
   scanf("%d%d", &n, &k);

   for (int l, r; n--; ans += (r - l + 1))
      scanf("%d%d", &l, &r);

   ans = ((ans + k - 1) / k) * k - ans;
   printf("%d", ans);

   return 0;
}