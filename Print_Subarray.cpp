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

void substring(string Ip, string Op)
{
    if (Ip.empty())
    {
        cout << Op << endl;
        return;
    }
    char first_chacter = Ip[0];
    Ip.erase(0, 1);
    substring(Ip, Op);
    Op.push_back(first_chacter);
    substring(Ip, Op);
    return;
}

void solve()
{
    string Ip, Op;
    cin >> Ip;
    substring(Ip, Op);

    return;
}