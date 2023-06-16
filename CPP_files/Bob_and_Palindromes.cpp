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

#define mod 1000000007

int power(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res *1ll* a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }

    return res;
}

int expoInv(int a, int b)
{
    return power(power(a, b), mod - 2);
}

int sum(int a, int b) { return (a + b ) % mod; }

int solves(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i + 1 <= n)
        {
            ans = sum(ans, (2 * expoInv(26, i / 2)) % mod);
            i++;
        }
        else
        {
            ans = sum(ans, expoInv(26, i / 2));
        }
    }
    return ans;
}

void solve()
{
    cout << solves(4) << el;


    return;
}