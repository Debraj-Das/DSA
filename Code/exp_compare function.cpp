/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int randomNumber()
{
    return std::uniform_int_distribution<int>(1, 10)(rng);
}
#define time(n) while ((double)(clock() - tt) / CLOCKS_PER_SEC < n)

#define int long long
#define el '\n'
#define sp ' '

inline int exp1(int a, int b)
{
    int x;
    for (x = 1; b; a *= a, b >>= 1)
        if (b & 1)
            x *= a;
    return x;
}

inline int exp2(int a, int b)
{
    int x;
    for (x = 1; b; a *= a, b >>= 1)
        x *= (a * (b & 1) + !(b & 1));
    return x;
}

bool solve()
{
    clock_t tt = clock();
    int n1 = 0;

    time(10)
    {
        exp1(randomNumber(), randomNumber());
        n1++;
    }

    int n2 = 0;
    tt = clock();
    time(10)
    {
        exp2(randomNumber(), randomNumber());
        n2++;
    }

    cout << n1 << el << n2 << el << (n2 - n1) << el;
    cout << (200.000 * (n2 - n1)) / (n2 + n1) << el << el;

    return (n2 > n1);
}

int32_t main()
{
    int t = 10, n = 0;

    while (t--)
        n += solve();

    cout << n << "/4" << el;

    return 0;
}
