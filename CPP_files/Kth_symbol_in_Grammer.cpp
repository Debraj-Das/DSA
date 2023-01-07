/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;
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
    cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

bool val(bool ver, int k)
{
    if (ver)
    {
        if (k % 2)
            return 0;
        else
            return 1;
    }
    else
    {
        if (k % 2)
            return 1;
        else
            return 0;
    }
}

bool grammer(int n, int k)
{
    if (k == 0)
        return 0;
    bool ver = grammer(n - 1, k / 2);
    return val(ver, k);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << grammer(n - 1, k - 1) << endl;

    return;
}