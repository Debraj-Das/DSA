/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
const int mod = 1e9 + 7;

inline long long invM(long long a)
{
   int b = mod - 2;
   long long ans = 1;

   while (b)
   {
      if (b & 1)
         ans = (1ll * ans * a) % mod;
      a = (1ll * a * a) % mod;
      b >>= 1;
   }

   return ans;
}

int main()
{
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0), std::cout.tie(0);
   int fac[100001];
   fac[0] = 1;
   for (int i = 1; i < 100001; i++)
      fac[i] = (1ll * fac[i - 1] * i) % mod;

   int t, n, a, b, c;
   std::cin >> t;
   while (t--)
   {
      std::cin >> n >> a >> b >> c;
      std::cout << (1ll * fac[n] * invM(((1ll * fac[a] * fac[b]) % mod) * fac[c] % mod)) % mod << '\n';
   }

   return 0;
}
