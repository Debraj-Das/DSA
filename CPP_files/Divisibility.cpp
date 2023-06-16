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

int combination(int l, vector<int> &arr)
{
    int ans = 1, i = 0;
    while (l)
    {
        if (l & 1)
            ans = ((ans * arr[i]) / __gcd(ans, arr[i]));
        i++;
        l >>= 1;
    }
    return ans;
}

int numDivisible(int l, int r, vector<int> arr)
{
    const int n = (1 << arr.size());
    int ans = 0;
    for (int i = 1 , mul; i < n; i++)
    {
        mul = combination(i, arr) ;
        if (__builtin_popcount(i) & 1)
            ans += (r / mul) - ((l - 1) /mul);
        else
            ans -= (r /mul) - ((l - 1) /mul);
    }
    return ans;
}

void solve()
{
    cout << numDivisible(5, 10, {2, 3, 4}) << el;

    return;
}