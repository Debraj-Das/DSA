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

void solve()
{
    map<int, int> fre;
    int n;
    cin >> n;
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        fre[x]++;
    }
    int ans = 1, num = 0, x;
    auto iter = fre.begin();
    for (int num = 0, x; num < n; ++iter)
    {
        x = (*iter).first;
        if (num < x)
        {
            num += (fre[x] - 1);
            if (num >= x)
                ++ans;
            num++;
        }
        else
        {
            num += fre[x];
        }
    }
    cout << ans << endl;

    return;
}