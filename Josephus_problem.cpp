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



int josephus_problem(forward_list<int> &man, int n, int k, auto begin)
{
    if (n==1)
        return man.front();

    for (int i = 1; i < k; ++i, begin++)
        if (begin == man.end())
            begin = man.begin();

    if ((begin) == man.end())
        begin = man.begin();
    auto del = begin++ ;
    man.remove((*del));

    return josephus_problem(man, n-1 , k, begin);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    forward_list<int> man;
    for (int i = n; i; --i)
        man.push_front(i);
    
    cout << josephus_problem(man, n, k, man.begin()) << endl;
    return;
}