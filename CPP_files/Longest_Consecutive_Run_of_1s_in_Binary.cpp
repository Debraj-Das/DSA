/*
     অভিজ্ঞতা একটি কঠিন শিক্ষক,
     সে প্রথমে তোমার পরীক্ষা নেয় এবং
     পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>

using namespace std;

int solve(int n)
{
    int len = 0, largest_len = 0;
    while (n)
    {
        if (n & 1)
            len++;
        else if (len)
        {
            if (len > largest_len)
                largest_len = len;
            len = 0;
        }
        n = (n >> 1);
    }
    if (len > largest_len)
        largest_len = len;
    return largest_len;
}

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

    int t = 1, n;
    cin >> t;
    while (t--) // solve the problem inside of drive function for test cases.
    {
        cin >> n;
        cout << solve(n) << endl;
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
