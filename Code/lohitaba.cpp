#include <bits/stdc++.h>
using namespace std;

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}

void solve()
{
    int n;
    cin >> n;
    pair<int, int> ar[n];
    bool visit[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i].first;
        ar[i].second = i;
        visit[i] = false;
    }

    sort(ar, ar + n);

    int ans = 0;
    for (int i = 0, j; i < n; i++)
    {
        j = ar[i].second;
        if (visit[j] == false)
        {
            ans += ar[i].first;
            if (j)
                visit[j - 1] = true;
            visit[j] = true;
            if (j < n - 1)
                visit[j + 1] = true;
        }
    }

    cout << ans << '\n';

    return;
}
