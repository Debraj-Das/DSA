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

int pop_ele(stack<int> &s, stack<int> &min_st)
{
    if (s.empty())
        return -1;

    int elements = s.top();
    if (elements == min_st.top())
        min_st.pop();
    return elements;
}

void push_ele(stack<int> &s, stack<int> &min_st, int key)
{
    s.push(key);
    if (min_st.empty() or min_st.top() >= key)
        min_st.push(key);
    return;
}

int min_element(stack<int> &min_st)
{
    if (min_st.empty())
        return -1;
    else
        return min_st.top();
}

void solve()
{
    stack<int> s, min_st;
    //* no of query in stack
    int n, i, key;
    cin >> n;
    while (n--)
    {
        cin >> i;
        if (i == 1)
        {
            cin >> key;
            push_ele(s, min_st, key);
        }
        else if (i == 2)
        {
            cout << pop_ele(s, min_st) << endl;
        }
        else
        cout<<min_element(min_st)<<endl;
    }

    return;
}