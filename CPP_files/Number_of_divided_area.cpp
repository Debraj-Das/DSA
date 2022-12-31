/*
     অভিজ্ঞতা একটি কঠিন শিক্ষক,
     সে প্রথমে তোমার পরীক্ষা নেয় এবং
     পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

long long int number_of_divided_area(int n)
{
    long long int val;
    for (val = 1; n > 3; --n)
        val += (n - 2) + ((n - 1) * (n - 2) * (n - 3)) / 6;
    return val ;
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
    while (t--) 
    {
        cin >> n;
        cout << number_of_divided_area(n) << endl;
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
