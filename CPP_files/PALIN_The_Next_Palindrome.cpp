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

string num_palindrome(string n)
{
    int size = n.size();

    if (size % 2)
    {
        int mid = (size / 2);
        if (n[mid - 1] <= n[mid + 1])
        {
            int carry = 0;
            for (int i = mid; i >= 0; --i)
            {
                if (n[i] == '9')
                {
                    n[i] = '0';
                    carry = 1;
                }
                else
                {
                    n[i] += 1;
                    carry = 0;
                    break;
                }
            }
            if (carry)
            {
                reverse(n.begin(), n.end());
                n.push_back('1');
                reverse(n.begin(), n.end());
                size++;
            }
        }
    }

    for (int i = 0, j = size - 1; i < j; ++i, j--)
    {
        if (((i + 1) == j) && n[i] < n[j])
            n[i] += 1;
        n[j] = n[i];
    }
    return n;
}

void solve()
{
    string n;
    cin >> n;
    cout << num_palindrome(n) << endl;

    return;
}
