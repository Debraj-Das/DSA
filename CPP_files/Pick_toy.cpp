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
    // cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

int max_toy_no(string s)
{
    int ans = 0;
    unordered_map<char, int> unq;
    for (int i = 0, j = 0, size; s[j]; ++j)
    {
        unq[s[j]]++;
        size = unq.size();

        if (size == 2)
        {
            if (ans < (j - i + 1))
                ans = (j - i + 1);
        }
        else
        {
            while (size > 2)
            {
                unq[s[i]]--;
                if (unq[s[i]] == 0)
                    unq.erase(s[i]);
                size = unq.size();
                ++i;
            }
        }
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    cout << max_toy_no(s) << endl;

    return;
}
