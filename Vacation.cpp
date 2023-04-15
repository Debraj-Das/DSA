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
    int n, k = 3;
    cin >> n;
    int points[n][k];
    f(i, 0, n) f(j, 0, k) cin >>
        points[i][j];
    
    int dp[n][k];
    // intialize the first row of dp by the first row of points
    f(i, 0, k)
        dp[0][i] = points[0][i];
    // now we try to calculate the maximum points for each day of the each activity
    f(i, 1, n)
    {
        int max0 = dp[i - 1][0], max1 = -1;
        f(j, 1, k)
        {
            if (dp[i - 1][j] >= max0)
                max1 = max0, max0 = dp[i - 1][j];
            else if (dp[i - 1][j] >= max1)
                max1 = dp[i - 1][j];
        }
        f(j, 0, k)
        {
            dp[i][j] = points[i][j] + (dp[i - 1][j] == max0 ? max1 : max0);
        }
    }
    // now we have to find the maximum value of the last row of dp
    int ans = 0;
    f(i, 0, k)
        ans = max(ans, dp[n - 1][i]);
    cout << ans << el;
    return;
}
