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
    string s;
    cin >> s;
    vector<pair<char, int>> v;
    int n = 0;
    char c = s[0];
    f(0, s.size()) if (c != s[i])
    {
        v.push_back({c, n});
        c = s[i];
        n = 1;
    }
    else n++;
    v.push_back({c,n});

    // for(auto x:v)
    // cout<< x.first<<' '<<x.second<<el ; 

    n = v.size();
    if (n % 2 == 0)
    {
        cout << 0 << el;
        return;
    }
    f(0, n / 2) if ((v[i].first != v[n - 1 - i].first) or (v[i].second + v[n - 1 - i].second < 3))
    {
        cout << 0 << el;
        return;
    }

    n = v[n / 2].second + 1;
    if (n < 3)
        cout << 0 << el;
    else
        cout << n << el;
    return;
}