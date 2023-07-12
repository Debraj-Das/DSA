// Problem: B. LuoTianyi and the Table
// Contest: Codeforces - Codeforces Round 872 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1825/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

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

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n * m], min_e[2], max_e[2];
    min_e[0] = min_e[1] = INT_MAX;
    max_e[0] = max_e[1] = INT_MIN;
    for (int i = 0; i < (n * m); i++)
    {
        cin >> arr[i];
        if (arr[i] >= max_e[0])
        {
            max_e[1] = max_e[0];
            max_e[0] = arr[i];
        }
        else if (arr[i] > max_e[1])
            max_e[1] = arr[i];

        if (arr[i] <= min_e[0])
        {
            min_e[1] = min_e[0];
            min_e[0] = arr[i];
        }
        else if (arr[i] < min_e[1])
        {
            min_e[1] = arr[i];
        }
    }
    int diff = min((min_e[1] - min_e[0]), (max_e[0] - max_e[1])) * (min(m, n) - 1);
    diff = (max_e[0] - min_e[0]) * (m * n - 1) - diff;

    cout << diff << el;

    return;
}