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

int height(int arr[], int i, int dp[])
{
    if (arr[i] == -1)
        return 1;
    if (dp[i] != 0)
        return dp[i];
    return dp[i] = 1 + height(arr, arr[i] - 1, dp);
}

void solve()
{
    int n;
    cin >> n;
    int arr[n], dp[n] = {0}, ans = 1;
    f(i, 0, n) cin >> arr[i];
    f(i, 0, n)
        ans = max(ans, height(arr, i, dp));
    cout << ans << el;
    return;
}