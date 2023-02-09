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
    //	cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

int *Stock_Span(int arr[], int n)
{
    int *elements = new int[n], i = 0;
    for (stack<int> s; i < n; i++)
    {
        while (!s.empty() and (arr[s.top()] <= arr[i]))
            s.pop();
        elements[i] = s.empty() ? 1 : (i - s.top());
        s.push(i);
    }
    return elements;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int *ele = Stock_Span(arr, n);
    for (int i = 0; i < n; ++i)
        cout << ele[i] << ' ';
    cout << endl;
    delete ele;
    return;
}