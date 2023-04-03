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

string Max_freq(map<string, int> freq)
{
    auto pr = max_element(freq.begin(), freq.end(), [](const auto &x, const auto &y)
                          { return x.second < y.second; });
    return pr->first;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<string, int> freq;
    f(0, n - 1)
        freq[s.substr(i, 2)]++;
    cout << Max_freq(freq) << el;
    return;
}