/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

string check(int A, int B)
{
    if (A > B)
        return ">";
    else if (A < B)
        return "<";
    else
        return "=";
}

string solve(int A, int B, int C)
{
    if (A >= 0 and B >= 0)
        return check(A, B);
    else if (A >= 0 and B < 0)
    {
        if (C % 2)
            return ">";
        else
            return check(A, abs(B));
    }
    else if (A < 0 and B >= 0)
    {
        if (C % 2)
            return "<";
        else
            return check(abs(A), B);
    }
    else
    {
        if (C % 2)
            return check(A, B);
        else
            return check(abs(A), abs(B));
    }
    return "=";
}

void solve()
{
    int A = -3, B = 3, C = 2;
    cout << solve(A, B, C) << el;

    return;
}