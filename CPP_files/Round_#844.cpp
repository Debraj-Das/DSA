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

int sum_min(int t, int a, int b)
{
    return min((a + b), (t - a + b));
}

void solve()
{
    int w, d, h;
    int a, b, f, g;
    cin >> w >> d >> h;
    cin >> a >> b >> f >> g;
    int ans = sum_min(2 * w, (a + f), abs(b - g));
    ans = min(ans, sum_min(2 * d, (b + g), abs(a - f))) + h;
    cout << ans << endl;

    return;
}