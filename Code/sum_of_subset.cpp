#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int __t;
    cin >> __t;
    while (__t--)
        solve();

    return 0;
}

int bruteForce(int ar[], int n, int x)
{
    const int N = (1 << n);
    int ans = 0;
    for (int i = 0, j, sum; i < N; i++)
    {
        for (j = 0, sum = 0; j < n; j++)
            sum += ar[j] * ((i >> j) & 1);

        ans += (sum <= x);
    }

    return ans;
}

int midInMiddle(int ar[], int n, int x)
{
    const int m = n / 2, k = n - m, M = (1 << m), K = (1 << k);
    int A[M];

    for (int i = 0, j, sum; i < M; i++)
    {
        for (j = 0, sum = 0; j < m; j++)
            sum += ar[j] * ((i >> j) & 1);

        A[i] = sum;
    }
    sort(A, A + M);

    int ans = 0;
    for (int i = 0, j, sum; i < K; i++)
    {
        for (j = 0, sum = 0; j < k; j++)
            sum += ar[m + j] * ((i >> j) & 1);

        ans += distance(A, upper_bound(A, A + M, (x - sum)));
    }

    return ans;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int ans = midInMiddle(ar, n, x);
    int bns = bruteForce(ar, n, x);
    if (ans == bns)
    {
        cout << "YES" << el;
    }
    else
    {
        cout << "NO" << el;
        cout << ans << ' ' << bns << el;
    }

    return;
}
