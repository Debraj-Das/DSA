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

int gcd(int arr[], int n)
{
    int gcd = arr[0];
    f(1, n)
    {
        gcd = __gcd(gcd, arr[i]);
        if (gcd == 1)
            break;
    }
    return gcd;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    f(0, n) cin >> arr[i];
    int max_no = *max_element(arr, arr + n);
    max_no /= gcd(arr, n);
    if ((max_no - n) % 2)
        cout << "Alice";
    else
        cout << "Bob";
    return;
}