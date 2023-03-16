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

bool div_pos(int arr[], int n, int k, int min_val)
{
    int fri = 0, current_money = 0;
    for (int i = 0; i < n; ++i)
    {
        if (current_money + arr[i] >= min_val)
            fri++, current_money = 0;
        else
            current_money += arr[i];
        if (fri >= k)
            return true;
    }
    return false;
}

int k_partition(int arr[], int n, int k)
{
    int s = 0, e = 0, ans = 0, mid;
    f(0, n) e += arr[i];
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (div_pos(arr, n, k, mid))
            ans = mid, s = mid + 1;
        else
            e = mid - 1;
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    f(0, n) cin >> arr[i];
    cout << k_partition(arr, n, k) << el;
    return;
}