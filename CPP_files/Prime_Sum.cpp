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

int solves(int n)
{
    if (n <= 2)
        return 0;
    n++;
    vector<bool> prime(n , true);
    int i, j, ans;
    prime[0] = false;
    prime[1] = false;
    for (i = 2; i * i < n; i++)
        if (prime[i])
            for (j = i * i; j < n; j += i)
                prime[j] = false;

    for (i = 0, ans = 0; i < n / 2; i++)
        if (prime[i])
            for (j = i + 1; j < n; j++)
            {
                if (i + j >= n)
                    break;
                if (prime[j] and prime[j + i])
                    ans++;
            }
    return ans;
}

void solve()
{
    cout << solves(5) << el;
    return;
}