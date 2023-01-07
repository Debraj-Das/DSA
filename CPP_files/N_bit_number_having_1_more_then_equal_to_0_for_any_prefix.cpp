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
    cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void N_bit_number(string num, int ones, int zero, int n)
{
    if (n == 0)     //* base condition
    {
        cout << num << endl;
        return;
    }
        //* first decision
    num.push_back('1');
    N_bit_number(num, ones + 1, zero, n - 1);

        //* second decision but depend on prefix idea
    if (ones > zero)
    {
        num.pop_back();
        num.push_back('0');
        N_bit_number(num, ones, zero + 1, n - 1);
    }
    return;
}

void solve()
{
    int n;
    cin >> n;
    N_bit_number("", 0, 0, n);

    return;
}
