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

int count_string(string s, int n)
{
    if (n == 0) // base case
    {
        // cout << s << el;     // If I want to print the string
        return 1;
    }
    int string_count = count_string(s + '0', n - 1);
    if (s.empty() or s[s.size() - 1] == '0')
        string_count += count_string(s + '1', n - 1);

    return string_count;
}

int count2_string(int n)
{
    if (n == 0 or n == 1)
        return n + 1;
    return count2_string(n - 1) + count2_string(n - 2);
}
// short form of count2_string function
int CBS(int n) { return n > 1 ? CBS(n - 1) + CBS(n - 2) : n + 1; } // 2^n time complexity

// But using the matrix method, time complexity log(n)
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
                    // res.m[i][j] %= mod;
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
            T = T * T, n >>= 1;
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
            val = ((res.m[0][i] * b[i]) + val);
        return (val);
    }
};

void solve()
{
    int n;
    cin >> n;
    // cout << count_string("", n) << el;
    // cout << count2_string(n) << el;
    // cout << CBS(n) << el;
    Recurrence s({1, 1}, {1, 2});
    cout << s.nth_element(n)<<el;
    return;
}
