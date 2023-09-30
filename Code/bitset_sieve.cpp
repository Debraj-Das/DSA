#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;
bitset<N> prime;

void sieve()
{
    for (int i = 2, j; i * i < N; i++)
    {
        if (prime[i])
            continue;
        for (j = i * i; j < N; j += i)
            prime.set(j);
    }

    prime.flip();

    return;
}

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    sieve();
    solve();

    return 0;
}

void solve()
{
    // count the prime
    int n = 0;
    for (int i = 2; i < N; i++)
        n += prime[i];

    cout << n << '\n';

    return;
}
