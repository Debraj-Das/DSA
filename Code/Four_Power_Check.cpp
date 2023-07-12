/*
     অভিজ্ঞতা একটি কঠিন শিক্ষক,
     সে প্রথমে তোমার পরীক্ষা নেয় এবং
     পরে তার পাঠ দেয়।
*/
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n)
{
    if (!(n & (n - 1)))
    {
        while (n)
        {
            n = n >> 2;
            if (n == 1)
                return true;
        }
    }
    return false;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t, n;
    cin>>t ;
    while (t--)
    {
        cin >> n;
        cout<<isPowerOfFour(n)<<endl;
    }
    return 0;
}