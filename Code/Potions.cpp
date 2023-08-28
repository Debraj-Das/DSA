#include <bits/stdc++.h>

using namespace std;

#define int long long
#define el '\n'
#define sp ' '

int32_t main()
{
    int n, h, x;
    cin >> n >> h >> x;
    x -= h;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        ans += (!ans and h >= x) * (i + 1);
    }

    cout << ans << el;

    return 0;
}