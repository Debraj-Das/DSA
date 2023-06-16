/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

vector<int> decode(vector<int> encoded)
{
    // Length of Original Array and it is odd
    const int n = encoded.size() + 1;
    // total is XOR of all numbers from 1 to n
    int total = 0, odd = 0;
    for (int i = 1; i <= n; i++)
        total ^= i;
    // odd is XOR of last n-1 elements in orginial array
    for (int i = 1; i < n - 1; i += 2)
        odd ^= encoded[i];
    vector<int> ans(n);
    // first element is total XOR odd (only first element is one time other are two times)
    ans[0] = total ^ odd;
    for (int i = 1; i < n; i++)
        ans[i] = ans[i - 1] ^ encoded[i - 1];
    return ans;
}

void solve()
{

    return;
}