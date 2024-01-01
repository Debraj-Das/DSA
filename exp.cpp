#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool check(vector<int> &b, int n, int k, ll mid)
{
    ll cnt = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        int par = -1;
        ll lcm = 1;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                ll g = __gcd(lcm, 1LL * b[j]);
                lcm = lcm * b[j] / g;
                par *= -1;
            }
        }
        cnt += par * (mid / lcm);
    }
    return cnt < k;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll L = 1, R = 1e11;
    ll ans = -1;

    while (L <= R)
    {
        ll mid = (L + R) / 2;
        if (!check(b, n, k, mid))
        {
            ans = mid;
            R = mid - 1;
        }
        else
            L = mid + 1;
    }

    assert(ans != -1);
    cout << ans << "\n";

    return 0;
}
