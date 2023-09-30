#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

inline void solve();

const int N = 1e6 + 1;
int prime[N] = {0};

void Divisor_sieve()
{
    for (int i = 2, j; i * i < N; i++)
    {
        if (prime[i])
            continue;

        for (j = i * i; j < N; j += i)
            prime[j] = i;
    }

    for (int i = 1; i < N; i++)
        if (prime[i] == 0)
            prime[i] = i;

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Divisor_sieve();

    solve();

    return 0;
}

void solve()
{

    int no = 0;
    for (int i = 2; i < N; i++)
        if (prime[i] == i)
            no++;

    cout << no << '\n';

    return;
}
