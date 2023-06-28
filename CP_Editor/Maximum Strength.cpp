// Problem: B. Maximum Strength
// Contest: Codeforces - Codeforces Round 879 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1834/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

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

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

void solve()
{
    string L, R;
    cin >> L >> R;
    int diff = 0, i = 0;
    if (L.length() != R.length())
    {
        diff = R[0] - '0';
        i = 1;
    }
    else
        for (i = 0; R[i]; i++)
            if (R[i] - L[i])
            {
                diff = abs(R[i] - L[i]);
                i++;
                break;
            }
    diff += 9 * (R.length() - i);
    cout << diff << el;
    return;
}