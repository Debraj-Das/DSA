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

int pop_ele(stack<int> &s, int &min_ele)
{
    if (s.empty())
        return -1;
    int element = s.top();
    s.pop();
    if (element < min_ele)
        min_ele = 2 * min_ele - element;
    return element;
}

void push_ele(stack<int> &s, int key, int &min_ele)
{
    if (s.empty())
    {
        s.push(key);
        min_ele = key;
    }
    else if (key < min_ele)
    {
        s.push(2 * key - min_ele);
        min_ele = key;
    }
    else
        s.push(key);
    return;
}

int top_ele(stack<int> &s, int min_ele)
{
    if (s.empty())
        return -1;
    else if (s.top() < min_ele)
        return min_ele;
    else
        return s.top();
}

void solve()
{
    stack<int> s;
    //* no of query in stack
    int n, i, key, min_ele;
    cin >> n;
    while (n--)
    {
        min_ele = INT_MIN;
        cin >> i;
        if (i == 1)
        {
            cin >> key;
            push_ele(s, key, min_ele);
        }
        else if (i == 2)
        {
            cout << pop_ele(s, min_ele) << endl;
        }
        else
            cout << min_ele << endl;
    }

    return;
}