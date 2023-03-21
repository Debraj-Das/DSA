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

inline int fast_power(int a, int b) // time complexity is log(b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}
const int mod = 1e9 + 7;

inline int mod_power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a, x %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return x;
}

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

int factorial(int n) { return n ? n * factorial(n - 1) : 1; }
int fib(int n) { return n > 1 ? fib(n - 1) + fib(n - 2) : n; }
void inc(int n)
{
    if (n == 0)
        return;
    inc(n - 1);
    cout << n << ' ';
    return;
}
void dec(int n)
{
    if (n == 0)
        return;
    cout << n << ' ';
    dec(n - 1);
    return;
}
int power(int a, int n) { return n ? a * power(a, n - 1) : 1; } // T(n)

void solve()
{
    int n;
    cin >> n;
    // inc(n); // print first n integer in increase number
    // dec(n);  // print first n integer in decrease number
    // cout << fib(n) << el; // calcuted the nth fibonnacy number
    // cout << factorial(n) << el;  // calculated the nth factorial number
    // cout << power(n, n) << el;   // calcutated the power function
    // cout << fast_power(n, n) << el; // it also calculated the power function
    // cout << mod_power(n, n) << el;   // it calculated and mod it

    return;
}
