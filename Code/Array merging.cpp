// Problem: B. Array merging
// Contest: Codeforces - Codeforces Round 875 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1831/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define max(a, b) (a) > (b) ? (a) : (b)
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

map<int, int> fm(int a[], int n)
{
    map<int, int> ma;
    int len = 1, pre_ele = a[0];
    f(i, 1, n)
    {
        if (a[i] != pre_ele)
        {
            ma[pre_ele] = max(len, ma[pre_ele]);
            pre_ele = a[i];
            len = 1;
        }
        else
            len++;
    }
    ma[pre_ele] = max(len, ma[pre_ele]);

    return ma;
}

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    f(i, 0, n) cin >> a[i];
    f(i, 0, n) cin >> b[i];
    map<int, int> ma = fm(a, n);
    map<int, int> mb = fm(b, n);
    int len = 0;
    for (auto &x : ma)
        len = max(len, x.second + mb[x.first]);
    for (auto &x : mb)
        len = max(len, x.second);

    cout << len << el;

    return;
}
