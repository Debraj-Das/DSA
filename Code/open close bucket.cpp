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
struct randomString
{
    std::string s;
    int n;

    randomString(std::string s = "abcdefghijklmnopqrstuvwxyz")
    {
        this->s = s;
        this->n = s.size() - 1;
    }

    int rdi()
    {
        return std::uniform_int_distribution<int>(0, n)(rng);
    }

    char rdc()
    {
        return s[rdi()];
    }

    std::string rds(size_t length)
    {
        std::string ans(length, 0);
        for (size_t i = 0; i < length; i++)
            ans[i] = s[rdi()];

        return ans;
    }
};

/*
    Add this line before used it if it is not present
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

    randomString rc("()?");
    rc.rds(10) -> 10 length string made by "()?"
    rc.rdc() -> random char from "()?"
*/

#define int long long
#define el '\n'
#define sp ' '

#define f(i, a, b) for (int i = a; i < (b); i++)

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int __t;
    cin >> __t;
    while (__t--)
        solve();

    return 0;
}

int dp[5001][5001];
int n;
string s;

int rec(int i, int open)
{
    if (open < 0)
    {
        return 0;
    }

    if (i == n)
    {
        return (open == 0);
    }

    if (dp[i][open] != -1)
        return dp[i][open];

    if (s[i] == '(')
    {
        dp[i][open] = rec(i + 1, open + 1);
    }
    else if (s[i] == ')')
    {
        dp[i][open] = rec(i + 1, open - 1);
    }
    else
    {
        dp[i][open] = rec(i + 1, open + 1) + rec(i + 1, open - 1);
    }

    return dp[i][open];
}

int test(int i, int open)
{
    if (open < 0)
    {
        return 0;
    }

    if (i == n)
    {
        return (open == 0);
    }

    if (s[i] == '(')
        return test(i + 1, open + 1);

    if (s[i] == ')')
        return test(i + 1, open - 1);

    return test(i + 1, open + 1) + test(i + 1, open - 1);
}

// Testing completed :)

void solve()
{
    n = 20;
    randomString rs("()?");

    s = rs.rds(n);

    memset(dp, -1, sizeof(dp));

    if (rec(0, 0) != test(0, 0))
        cerr << s << sp << rec(0, 0) << sp << test(0, 0) << el;

    return;
}
