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

#define int long long int

int sum_of_digit(int a)
{
    int x;
    while (a > 9)
    {
        for (x = 0; a; a /= 10)
            x += (a % 10);
        a = x;
    }
    return a;
}

inline int power(int a, int b)
{
    int x ;
    for (x = 1; b; b >>= 1, a *= a)
    {
        a = sum_of_digit(a);
        if (b & 1)
            x *= a, x = sum_of_digit(x);
    }
    return x;
}

void solve()
{
    int a , b ;
    cin>>a>>b ;
    cout<<power(a,b)<<endl;
    return;
}