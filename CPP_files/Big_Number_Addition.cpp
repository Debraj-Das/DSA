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
    // cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

string addition(string s1, string s2) //* addition two string as digit
{
    if (s1.length() > s2.length())
        swap(s1, s2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int sum, i, carry;
    string result;
    for (i = 0, carry = 0; i < s1.length(); ++i)
    {
        sum = (s1[i] - '0') + (s2[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (; i < s2.length(); ++i)
    {
        sum = (s2[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry)
        result.push_back('1');
    reverse(result.begin(), result.end());

    return result;
}

string multiply(string s, int n, int i = 0)
{
    string result;
    while (true)
    {
        if (n & 1)
            result = addition(result, s);
        n >>= 1;
        if (n == 0)
            break;
        else
            s = addition(s, s);
    }
    while (i--)
        result.push_back('0');

    return result;
}

string mul_two_string(string s1, string s2)
{
    reverse(s2.begin(), s2.end());
    string result;
    for (int i = 0; i < s2.length(); ++i)
        result = addition(multiply(s1, (s2[i] - '0'), i), result);

    return result;
}

string factorial(int n)
{
    string result ;
    if(n==0)
    result =  "1";
    else
    {
        result = "1";
        for(int i = 2;i<=n;++i)
        result = multiply(result,i);
    }
    return result ;
}

void solve()
{
    // string s1, s2;
    // cin >> s1 >> s2;
    // string sum = addition(s1, s2);
    // cout << "sum :" << sum << endl;
    // cout << "mul :" << mul_two_string(s1, s2) << endl;
    cout<<factorial(2000)<<endl;
    return;
}