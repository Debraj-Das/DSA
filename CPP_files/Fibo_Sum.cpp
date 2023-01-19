/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;
void solve();

#define ll long long int
const int mod = 1e9 + 7;

class Matrix
{
private:
    static const int sz = 2; //* size of Matrix

public:
    ll mat[sz][sz];
    Matrix()
    {
        memset(mat, 0, sizeof(mat));
    }

    void identity()
    {
        for (int i = 0; i < sz; i++)
        {
            mat[i][i] = 1;
        }
    }

    Matrix operator*(Matrix a)
    {
        Matrix res;
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    res.mat[i][j] += mat[i][k] * a.mat[k][j];
                    res.mat[i][j] %= mod;
                }
            }
        }
        return res;
    }

    Matrix operator^(int n)
    {
        Matrix res, T(*this);
        res.identity();
        for (Matrix T(*this); n; n >>= 1, T = (T * T))
            if (n & 1)
                res = res * T;

        return res;
    }
};

ll Fib(int n) 
{
    if(n<0)
    {
        cout<<"Enter nagive index"<<endl;
        exit(-1);
    }
    if (n == 0)
        return 0;
    if (n <= 2) //* edge basic case
        return 1;

    Matrix T;
    T.mat[0][0] = T.mat[0][1] = T.mat[1][0] = 1; // # chance depend on problem statement

    Matrix res = T ^ (n - 2);

    return (res.mat[0][0] + res.mat[0][1]) % mod; // # chance depend on base value
}

int fibSum(int n, int m)
{
    if (m == n)
        return Fib(n);

    return (Fib(m + 2) - Fib(n + 1) + mod) % mod;
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
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void solve()
{
    int n , m;
    cin>>n>>m;
    cout<<fibSum(n,m)<<endl;
    return;
}

