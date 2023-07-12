/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const int mod = 1e9 + 7;

struct Mat
{
    int sz;
    vector<vi> m;
    Mat(int size = 2)
    {
        sz = size;
        m.resize(sz);
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                m[i].push_back(0);
            }
        }
    }

    void identity()
    {
        for (int i = 0; i < sz; i++)
            m[i][i] = 1;
        return;
    }

    Mat operator*(Mat a)
    {
        Mat res(sz);
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }

    Mat operator^(int n)
    {
        Mat res(sz);
        res.identity();

        Mat T(*this);
        while (n)
        {
            if (n & 1)
                res = res * T;
            T = T * T , n >>= 1;
        }
        return res;
    }
};

struct Recurrence
{
private:
    int sz;
    int order;
    Mat *matrix;
    vi b;

public:
    Recurrence(vi coeffience = {1, 1}, vi base = {1, 1}, bool homo = true)
    {
        sz = coeffience.size();
        order = base.size();
        if (homo)
        {
            if (order != sz)
                exit(-1);
        }
        else
        {
            if (order != (sz - 1))
                exit(-1);
        }

        matrix = new Mat(sz);
        for (int i = 0; i < sz; ++i)
            matrix->m[0][i] = coeffience[i];

        for (int i = 1; i < order; ++i)
            matrix->m[i][i - 1] = 1;

        for (int i = order - 1; i >= 0; --i)
            b.push_back(base[i]);

        if (!homo)
        {
            matrix->m[sz - 1][sz - 1] = 1;
            b.push_back(1);
        }
    }

    ~Recurrence()
    {
        delete matrix;
    }

    int nth_element(int n) //* find the nth element
    {
        if (n < 0)
            return (-1);
        else if (n < order)
            return b[n];

        Mat T(*matrix);
        n = (n - order + 1); //~ assumsed element start from 0
        Mat res = T ^ n;

        long long val = 0;
        for (int i = 0; i < sz; ++i)
            val = ((res.m[0][i] * b[i]) % mod + val % mod);
        return (val % mod);
    }
};

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
    cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void solve()
{
    int n;
    Recurrence obj({1,1,1},{1,1},false);
    cin >> n;
    cout << obj.nth_element(n) << endl;

    return;
}
