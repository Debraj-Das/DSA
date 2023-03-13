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
/*
int my_gcd(int a, int b)
{
    if (b == 0)
        return a;
    my_gcd(b, a % b);
}
*/

int exended_Euclidean_algo(int a, int b, int gcd)
{
    if (b == 0)
        return 0;   //* we assumsed this value as 0, it can be any value
    int val = gcd - a * exended_Euclidean_algo(b, a % b, gcd);
    return (val / b);
}

void solve()
{
    int a, b;
    cin >> a >> b;
    int val = exended_Euclidean_algo(a, b, __gcd(a, b));    // T(log(a))
    cout << "x = " << (__gcd(a, b) - b * val) / a << el;
    cout << "y = " << val << el;
    return;
}