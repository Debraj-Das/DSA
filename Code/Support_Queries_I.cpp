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
    // cin >> t;
    while (t--)
        solve();

    return 0;
}

struct custom
{
private:
    int sum = 0;
    map<int, int> m;

public:
    void add(int x)
    {
        m[x]++;
        sum += x;
        return;
    }
    void remove(int x)
    {
        if (m.find(x) == m.end())
            return;
        m[x]--;
        if (m[x] == 0)
            m.erase(x);
        sum -= x;
        return;
    }
    int min()
    {
        if (m.empty())
            return -1;
        return m.begin()->first;
    }
    int max()
    {
        if (m.empty())
            return -1;
        return m.rbegin()->first;
    }
    int sum_ele() { return sum; }
};

void solve()
{
    int Q;
    cin >> Q;
    custom a;
    int x;
    string s;
    while (Q--)
    {
        cin >> x;
        switch (x)
        {
        case 1:
        {
            cin >> x;
            a.add(x);
        }
        break;
        case 2:
        {
            cin >> x;
            a.remove(x);
        }
        break;
        case 3:
        {
            getline(cin, s);
            cout << a.min() << el;
        }
        break;
        case 4:
        {
            getline(cin, s);
            cout << a.max() << el;
        }
        break;
        case 5:
        {
            getline(cin,s);
            cout << a.sum_ele() << el;
        }
        break;

        default:
            cout << "Enter Wrong Number" << el;
            break;
        }
    }
    return;
}