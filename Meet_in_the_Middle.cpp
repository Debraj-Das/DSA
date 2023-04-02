/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define el '\n'
#define f(a, b) for (int i = a; i < b; i++)
#define fr(a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void Solve();

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
        Solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

long long solve(int n, int x, vector<int> a)
{
    vector<int> v;
    int range, i, y, j, c, no;
    for (i = 0, range = (1 << (n / 2)); i < range; ++i)
    {
        for (j = 0, y = 0, c = i; c; c >>= 1, j++)
            if (c & 1)
                y += a[j];
        if (y <= x)
            v.push_back(y);
    }

    // for(auto x:v)
    // cout<< x<<' ' ; 
    // cout<< el ; 

    sort(v.begin(), v.end());
    for (i = 0, no = 0, range = (1 << (n - n / 2)); i < range; ++i)
    {
        for (j = 0, y = 0, c = i; c; c >>= 1, j++)
            if (c & 1)
                y += a[n/2+j];
        // cout<< y<<' ' ; 
        no += (upper_bound(v.begin(), v.end(), (x - y)) - lower_bound(v.begin(), v.end(), (x - y)));
    }
    // cout<< el ; 
    return no;
}

void Solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    f(0, n) cin >> a[i];
    cout << solve(n, x, a) << el;

    return;
}