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

void draw_print(int n, int a, int b)
{
    for (; a; a--, n--)
        cout << "1:0" << endl;
    for (; b; b--, n--)
        cout << "0:1" << endl;
    for (; n; --n)
        cout << "0:0" << endl;
    return;
}

void print(int n, int a, int b)
{
    if (a > (n - 2))
    {
        for (int i = 0; i < (n - 2); ++i)
            cout << "1:0" << endl;
        if (b)
        {
            cout << (a - n + 2) << ':' << 0 << endl;
            cout << 0 << ':' << b << endl;
        }
        else
        {
            cout << "1:0" << endl;
            cout << (a - n + 1) << ':' << 0 << endl;
        }
    }
    else
    {
        for (; a; a--, n--)
            cout << "1:0" << endl;
        for (n--; n; b--, n--)
            cout << "0:1" << endl;
        cout << 0 << ':' << b << endl;
    }
    return;
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (n == 1)
    {
        if (a == b)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        cout << a << ':' << b << endl;
    }
    else
    {
        if (n > (a + b))
        {
            cout << (n - a - b) << endl;
            draw_print(n, a, b);
        }
        else
        {
            cout << 0 << endl;
            print(n, a, b);
        }
    }

    return;
}