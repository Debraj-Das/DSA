/*
	 অভিজ্ঞতা একটি কঠিন শিক্ষক,
	 সে প্রথমে তোমার পরীক্ষা নেয় এবং
	 পরে তার পাঠ দেয়।
*/
#include <bits/stdc++.h>
using namespace std;

void Pint_binary_form(int n);

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
    while (t--) // Count_bit the problem inside of drive function for test cases.
    {
        cin >> n;
        Pint_binary_form(n);
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void Pint_binary_form(int n)
{
    int count = 0;
    while (n)
    {
        cout<<(n&1);
        n = (n>>1);
    }
    cout<<'\n';
    return ;
}
