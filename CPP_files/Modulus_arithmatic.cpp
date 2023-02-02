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

const int m = 7;

int addm(int a, int b)
{
    a += b;
    b = a % m;
    if (b < 0)
        b += m;
    return b;
}

int mulm(int a, int b)
{
    long long c = (a % m) * (b % m);
    c %= m;
    if (c < 0)
        c += m;
    return c;
}

int powrm(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = mulm(res, x);
        y >>= 1;
        x = mulm(x, x);
    }
    return res;
}

int divm(int x, int y)
{
    return mulm(x, powrm(y, m - 2));
}

int facm(int x)
{
    if (x == 0 || x == 1)
        return 1;
    int res = x;
    while (--x)
    {
        res = mulm(res, x);
    }
    return res;
}

int nCr(int n , int r)
{
    if(n<r)
    return -1;
    int num = 1 , deno = 1 ;
    for(int i = 0 ; i< r ; ++i)
    {
        num = mulm(num,(n-i));
        deno = mulm(deno,i+1);
    }
    return divm(num,deno);
}

void solve()
{
    // cout << addm(4, 5) << endl;
    // cout<<mulm(64,32)<<endl;
    // cout<<divm(56,2)<<endl;
    // cout << facm(39024783) << endl;
    cout<< nCr(5,2) <<endl; 
    return;
}