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

int Minimum_window_substring(string s, string t)
{
    unordered_map<char, int> unique_element;
    for (int i = 0; t[i]; ++i)
        unique_element[t[i]]++;

    int ans = -1, i = 0, j = 0, size = unique_element.size();
    while (s[j])
    {
        while (size && s[j])
        {
            if (unique_element.find(s[j]) != unique_element.end())
            {
                unique_element[s[j]]--;
                if (unique_element[s[j]] == 0)
                    size--;
            }
            ++j;
        }
        if ((ans == -1)&&(size == 0))
            ans = (j - i);
        while ((size == 0) && (i <= j))
        {
            if (unique_element.find(s[i]) != unique_element.end())
            {
                unique_element[s[i]]++;
                if (unique_element[s[i]] == 1)
                    size++;
            }
            ++i;
        }
        if (ans > (j - i + 1))
            ans = (j - i + 1);
    }
    return ans;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    cout << Minimum_window_substring(s, t) << endl;

    return;
}
