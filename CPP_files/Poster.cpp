/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(a, b) for (int i = a; i < b; i++)
#define fr(a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k > (n - k))
    {
        f(0, n - k) cout << "RIGHT" << el;
        fr(n - 1, 0)
        {
            cout << "PRINT " << s[i] << el;
            if (i)
                cout << "LEFT" << el;
        }
    }
    else
    {
        f(0, k-1) cout << "LEFT" << el;

        f(0, n)
        {
            cout << "PRINT " << s[i] << el;
            if (i != (n - 1))
                cout << "RIGHT" << el;
        }
    }

    return;
}