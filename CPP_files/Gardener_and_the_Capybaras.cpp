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

void name(string s)
{
    int n = s.length(), i;
    if (s[0] == s[n - 1])
    {
        cout << s[0] << ' ' << s.substr(1, n - 2) << ' ' << s[0] << endl;
    }
    else if (s[0] == 'a')
    {
        for (i = 1; i < (n - 1); ++i)
        {
            if (s[i] == 'b')
                break;
        }
        
        if (i < (n - 1))
            cout << s.substr(0, i) << ' ' << s.substr(i, n - i-1) << ' ' << s[n - 1] << endl;
        else
            cout << s.substr(0, n - 2) << ' ' << s[n - 2] << ' ' << s[n - 1] << endl;
    }
    else
    {
        for (i = 1; i < (n - 1); ++i)
        {
            if (s[i] == 'a')
                break;
        }
        if (i < (n - 1))
            cout << s.substr(0, i) << ' ' << s[i] << ' ' << s.substr(i + 1, n - 1-i) << endl;
        else
            cout << s[0] << ' ' << s.substr(1, n - 2) << ' ' << s[n-1] << endl;
    }
    return;
}

void solve()
{
    string s;
    cin >> s;
    name(s);

    return;
}

