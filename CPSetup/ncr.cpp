const int N = 200000 + 5;
ll fact[N], invfact[N];

long long invM(ll a)
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

void factorialcul()
{
   fact[0] = 1;
   for (int i = 1; i < N; i++)
   {
      fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
   }

   invfact[N - 1] = invM(fact[N - 1]);
   for (int i = N - 2; i >= 0; --i)
   {
      invfact[i] = ((invfact[i + 1] % mod) * (i + 1)) % mod;
   }

   return;
}

long long ncr(ll n, ll r)
{
   if (r > n)
      return 0ll;

   long long res = fact[n] % mod;
   res = (res * (invfact[n - r] % mod)) % mod;
   res = (res * (invfact[r] % mod)) % mod;

   return res;
}

