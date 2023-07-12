// Problem: E1. Permutation Minimization by Deque
// URL: https://codeforces.com/contest/1579/problem/E1
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

inline int exp(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
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

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    f(i, 0, n) cin >> arr[i];
    stack<int> s;
    s.push(arr[0]);
    arr[0] = 0;
    f(i, 1, n) if (arr[i] < s.top())
    {
        s.push(arr[i]);
        arr[i] = 0;
    }
    int ans[n], i;
    for (i = 0; !s.empty(); i++)
    {
        ans[i] = s.top();
        s.pop();
    }
    f(j, 0, n) if (arr[j])
    {
        ans[i] = arr[j];
        i++;
    }

    f(i, 0, n) cout << ans[i] << sp;
    cout << el;
    return;
}
