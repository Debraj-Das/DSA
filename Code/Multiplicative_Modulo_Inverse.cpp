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

int exended_Euclidean_algo(int a, int b)
{
    if (b == 0)
        return 0;
    int val = 1 - a * exended_Euclidean_algo(b, a % b);
    return (val / b);
}

void solve()
{
    int a, m;
    cin >> a >> m;
    if (__gcd(a, m) == 1)
    {
        int inverse = (1 - m * exended_Euclidean_algo(a, m)) / a;
        inverse = (inverse % m + m) % m;
        cout << "Inv: " << inverse << el;
    }
    else
        cout << "No inverse present" << el;
    return;
}
