#include <bits/stdc++.h>
using namespace std;

void solve();

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    map<int, int> M;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        M[x]++;
    }

    priority_queue<pair<int, int>> q;

    long long ans = 1LL * n * (n - 1) / 2;

    for (auto it : M)
    {
        if (it.second > 1)
        {
            q.push({it.second, it.first});
            ans -= 1LL * it.second * (it.second - 1) / 2;
        }
    }

    for (int i = 0; i < k; i++)
    {
        if (q.empty())
            break;
        auto it = q.top();
        q.pop();
        ans += it.first - 1;
        it.first--;
        if (it.first > 1)
            q.push(it);
    }

    cout << ans << "\n";
}