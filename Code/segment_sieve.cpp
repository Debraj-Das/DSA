#include <bits/stdc++.h>
using namespace std;

inline void solve();

const int N = 1e6 + 1;
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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}

vector<int> segmentSieve(int a, int b)
{
    vector<int> p(b - a + 1, false);
    
    for (int i = 2, j; i * i <= b; i++)
    {
        if (prime[i] == 0)
            continue;

        j = ((a + i - 1) / i) * i;

        for (j += i * (j == i); j <= b; j += i)
            p[j - a] = true;
    }

    return p;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    vector<int> p = segmentSieve(a, b);

    int ans = 0, n = p.size();
    for (int i = 0; i < n; i++)
        ans += (p[i] == 0);

    cout << ans << '\n';

    return;
}
