// Problem: A. Counting Orders
// URL: https://codeforces.com/contest/1827/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define sp ' '
#define f(i, a, b) for (int i = a; i < (b); i++)
#define fr(i, a, b) for (int i = a; i >= (b); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define F first
#define S second
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define mod (1000000007)

inline int mul(int a, int b)
{
    int ans = (a * b) % mod;
    return ans;
}

void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

int binary(int l, int r, int arr[], int target)
{
    int i = l, mid = l;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] >= target and (mid == i + 1 or arr[mid - 1] < target))
        {
            mid--;
            break;
        }
        else if (arr[mid] >= target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return mid - i + 1;
}

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    f(i, 0, n) cin >> a[i];
    f(i, 0, n) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    f(i, 0, n) if (b[i] >= a[i])
    {
        cout << 0 << el;
        return;
    }

    int ans = 1, m;
    f(i, 0, n)
    {
        m = binary(i, n - 1, b, a[i]);
        ans = mul(ans, m);
    }
    cout << ans << el;

    return;
}
