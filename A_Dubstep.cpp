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

bool check(string s, int i)
{
    if (i + 2 < s.size() and s[i] == 'W' and s[i + 1] == 'U' and s[i + 2] == 'B')
        return true;
    return false;
}

void solve()
{
    string s, out;
    cin >> s;
    for (int i = 0, flug = 0; s[i]; flug ? i += 3 : i++)
    {
        if (check(s, i))
            flug = 1;
        else if (!out.empty() and flug)
        {
            out.push_back(' ');
            out.push_back(s[i]);
            flug = 0;
        }
        else
            out.push_back(s[i]), flug = 0;
    }
    cout << out << el;

    return;
}