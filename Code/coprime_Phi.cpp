#include <bits/stdc++.h>
using namespace std;

inline void solve();

const int N = 1e6 + 1;
int phi[N];

void coprime()
{
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2, j; i < N; i++)
        if (phi[i] == i)
            for (j = i; j < N; j += i)
                phi[j] -= (phi[j] / i);

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    coprime();
    solve();

    return 0;
}

void solve()
{
    int n = 10 + 1;
    for (int i = 2; i < n; i++)
        cerr << i << ' ' << phi[i] << '\n';
    cerr << '\n';

    return;
}
