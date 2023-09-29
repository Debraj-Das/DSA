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
    int n, m;
    cin >> n >> m;
    pair<int, int> ar[n][m];
    for (int i = 0, j; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> ar[i][j].first;

    ar[0][0].second = 0;
    for (int i = 1; i < n; i++)
    {
        ar[i][0].first += ar[i - 1][0].first;
        ar[i][0].second = max(-ar[i][0].first, ar[i - 1][0].second);
    }
    for (int i = 1; i < m; i++)
    {
        ar[0][i].first += ar[0][i - 1].first;
        ar[0][i].second = max(-ar[0][i].first, ar[0][i - 1].second);
    }

    for (int i = 1, j, t1, t2; i < n; i++)
        for (j = 1; j < m; j++)
        {
            t1 = max(ar[i][j - 1].second, -(ar[i][j - 1].first + ar[i][j].first));
            t2 = max(ar[i - 1][j].second, -(ar[i - 1][j].first + ar[i - 1][j].first));
            if (t1 < t2)
            {
                ar[i][j].first += ar[i][j - 1].first;
                ar[i][j].second = t1;
            }
            else
            {
                ar[i][j].first += ar[i - 1][j].first;
                ar[i][j].second = t2;
            }
        }
    cout << ar[n - 1][m - 1].second << '\n';

    return;
}
