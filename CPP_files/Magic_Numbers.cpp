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
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

void solve()
{
    int n, a, m = 0;
    cin >> n;
    while (n)
    {
        a = n % 10, n /= 10;
        switch (a)
        {
        case 4:
            m++;
            break;
        case 1:
            m = 0;
            break;
        default:
            m = 3;
            break;
        }
        if (m > 2)
        {
            cout << "NO" << el;
            return;
        }
    }
    if (m)
        cout << "NO" << el;
    else
        cout << "YES" << el;
    return;
}