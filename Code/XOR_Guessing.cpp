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

int query(int arr[], int n = 100)
{
    cout << "? ";
    f(0, n) cout << arr[i] << ' ';
    cout << endl;
    int y;
    cin >> y;
    return y;
}

void solve()
{
    // bitset<32> x((1 << 14) -1);
    // cout << x << el;
    int arr[100], y, num;
    f(0, 100) arr[i] = (i + 1);
    y = query(arr);
    num = y & (127 << 7);
    f(0, 100) arr[i] <<= 7;
    y = query(arr);
    num += (y & 127);
    cout << "! " << num << endl;
    return;
}