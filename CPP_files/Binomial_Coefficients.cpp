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
    //	cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

// Time Complexity is O(n*k) and space Complexity O(n*k)
int binomial_Coefficients(int n, int k)
{
    int table[n + 1][k + 1] = {0};
    for (int i = 0, j, m; i <= n; ++i)
        for (j = 0, m = min(i, k); j <= m; ++j)
        {
            if (j == 0 or j == i)
                table[i][j] = 1;
            else
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
        }
    return table[n][k];
}

// My solution With less space Time Complexity O(n*k) and Space Complexity O(n)
int less_binomial_Coefficients(int n, int k)
{
    int table[k + 1] = {0};
    for (int i = 0, j, m, pre, temp; i <= n; ++i)
        for (j = 0, m = min(i, k), pre = 0; j <= m; ++j)
            if (i == j)
                table[j] = 1;
            else
            {
                temp = table[j];
                table[j] += pre;
                pre = temp;
            }

    return table[k];
}

// This Solution not working for interger Overflow but method right, time Complexity O(k) and space complexity O(1)
int k_binomial_Coefficients(int n, int k)
{
    long long int vaule = 1;
    for (int i = 0; i < k; ++i)
        vaule = (vaule * 1ll * (n - i)) / (i + 1);
    return vaule;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << binomial_Coefficients(n, k) << endl;
    cout << less_binomial_Coefficients(n, k) << endl;
    return;
}