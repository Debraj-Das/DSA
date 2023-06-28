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
    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        cout << "YES" << el;
        return;
    }
    else if (m > n or n % 3)
    {
        cout << "NO" << el;
        return;
    }
    queue<int> q;
    q.push(n);
    int ele, p1, p2;
    while (!q.empty())
    {
        ele = q.front();
        q.pop();
        p1 = (ele / 3);
        p2 = 2 * p1;
        if (p1 == m or p2 == m)
        {
            cout << "YES" << el;
            return;
        }
        else if (p1 > m and p1 % 3 == 0)
            q.push(p1), q.push(p2);
        else if (p2 > m and p2 % 3 == 0)
            q.push(p2);
    }
    cout << "NO" << el;

    return;
}