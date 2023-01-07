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

void balenced_patenthesis(string s, int fp, int bp)
{
    if (fp == 0)    //* base condition
    {
        while (bp)
        {
            s.push_back(')');
            bp--;
        }
        cout << s << endl;
        return;
    }
        //* first desition
    s.push_back('(');
    balenced_patenthesis(s, fp - 1, bp);
    s.pop_back();
        //* second desition
    if (fp < bp)
    {
        s.push_back(')');
        balenced_patenthesis(s, fp, bp - 1);
    }

    return;
}

void solve()
{
    int n;
    cin >> n;
    balenced_patenthesis("", n, n);

    return;
}
