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
    // cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void insert(vector<int> &v, int ele)
{
    if (v.size() == 0 || v[v.size() - 1] <= ele)
    {
        v.push_back(ele);
        return;
    }
    int temp = v.back();
    v.pop_back();
    insert(v, ele);
    v.push_back(temp);
    return;
}

void recursion_sorting(vector<int> &v)
{
    if (v.size() == 1)
        return;
    int temp = v.back();
    v.pop_back();
    recursion_sorting(v);
    insert(v, temp);
    return;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        v.push_back(x);
    }
    recursion_sorting(v);
    for (auto x : v)
        cout << x << endl;

    return;
}