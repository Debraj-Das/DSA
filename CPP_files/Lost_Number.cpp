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
    int v[6] = {0}, p = 7418880, q[5];
    f(1, 5)
    {
        cout << "? " << i << ' ' << (i + 1) << endl;
        cin >> q[i - 1];
    }
    q[4] = p / (q[0] * q[2]);

    p = -1;

    if (!(q[0] % 23) and q[1] % 23)
        v[0] = 23, p = 0;
    for (int i = 0; i < 4 and p < 0; ++i)
        if (!(q[i] % 23 or q[i + 1] % 23))
            v[i + 1] = 23, p = i + 1;
    if (p < 0)
        v[5] = 23, p = 5;
    // f(0, 6) cout << v[i] << ' ' << p << ' ';
    // cout << endl;
    for (int i = p; i < 5; ++i)
        v[i + 1] = q[i] / v[i];
    for (int i = p; i > 0; --i)
        v[i - 1] = q[i - 1] / v[i];
    cout << "! ";
    f(0, 6)
            cout
        << v[i] << ' ';
    cout << endl;
    return;
}