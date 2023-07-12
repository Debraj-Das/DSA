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

string prefix(string s)
{
    string res;
    stack<char> store;
    for (int i = 0; s[i]; i++)
    {
        if (isalpha(s[i]))
            res.push_back(s[i]);
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            store.push(s[i]);
        else if (s[i] == ')')
        {
            res.push_back(store.top());
            store.pop();
        }
    }
    while (store.size())
    {
        res.push_back(store.top());
            store.pop();
    }
    return res ;
}

void solve()
{
    string s;
    cin >> s;
    cout << prefix(s) << endl;

    return;
}