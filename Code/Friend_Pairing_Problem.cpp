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

int no_of_pairing_possibility(int n)
{
    if (n == 0 or n == 1)
        return 1;
    return no_of_pairing_possibility(n - 1) + (n - 1) * no_of_pairing_possibility(n - 2);
}
// Short form of the above function

int PP(int n) { return n > 1 ? PP(n - 1) + (n - 1) * PP(n - 2) : 1; }

// DP solution

int dp_solution(int n) // Linear solution
{
    int no = 1;
    for (int i = 1, pre = 1, temp; i < n; ++i)
    {
        temp = no + i * pre;
        pre = no;
        no = temp;
    }
    return no;
}

// Recurrence Formula always solve by dynamic programing by polynomial time complexity

void solve()
{
    int n;
    cin >> n;
    // cout << no_of_pairing_possibility(n) << el;
    // cout << PP(n) << el;
    cout << dp_solution(n) << el;

    return;
}