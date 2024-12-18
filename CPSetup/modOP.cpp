inline long long add(long long a, long long b)
{
    return (0ll + a % mod + b % mod) % mod;
}

inline long long sub(long long a, long long b)
{
    return (0ll + a % mod - b % mod + mod) % mod;
}

inline long long mul(long long a, long long b)
{
    return (1ll*(a % mod) * (b % mod)) % mod;
}

// little format theorem
inline long long inv(long long a)
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

inline long long div(long long a, long long b)
{
   return (1ll*(a%mod)*(inv(b)))%mod;
}

inline long long expM(long long a, int b)
{
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
