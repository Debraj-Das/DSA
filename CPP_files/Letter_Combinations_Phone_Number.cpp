/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(a, b) for (int i = a; i < b; i++)
#define fr(a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
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
        solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void combination(string digits, string s, vector<string> &vs)
{
    if (digits.empty())
    {
        vs.push_back(s);
        return;
    }
    char first = digits[0];
    digits.erase(0, 1);
    switch (first)
    {
    case '2':
    {
        combination(digits, (s + 'a'), vs);
        combination(digits, (s + 'b'), vs);
        combination(digits, (s + 'c'), vs);
    }
    break;
    case '3':
    {
        combination(digits, (s + 'd'), vs);
        combination(digits, (s + 'e'), vs);
        combination(digits, (s + 'f'), vs);
    }
    break;
    case '4':
    {
        combination(digits, (s + 'g'), vs);
        combination(digits, (s + 'h'), vs);
        combination(digits, (s + 'i'), vs);
    }
    break;
    case '5':
    {
        combination(digits, (s + 'j'), vs);
        combination(digits, (s + 'k'), vs);
        combination(digits, (s + 'l'), vs);
    }
    break;
    case '6':
    {
        combination(digits, (s + 'm'), vs);
        combination(digits, (s + 'n'), vs);
        combination(digits, (s + 'o'), vs);
    }
    break;
    case '7':
    {
        combination(digits, (s + 'p'), vs);
        combination(digits, (s + 'q'), vs);
        combination(digits, (s + 'r'), vs);
        combination(digits, (s + 's'), vs);
    }
    break;
    case '8':
    {
        combination(digits, (s + 't'), vs);
        combination(digits, (s + 'u'), vs);
        combination(digits, (s + 'v'), vs);
    }
    break;
    case '9':
    {
        combination(digits, (s + 'w'), vs);
        combination(digits, (s + 'x'), vs);
        combination(digits, (s + 'y'), vs);
        combination(digits, (s + 'z'), vs);
    }
    break;

    default:
        break;
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> vs;
    if (digits.empty())
        return vs;
    combination(digits, "", vs);
    return vs;
}

void solve()
{
    string s;
    cin >> s;
    vector<string> vs = letterCombinations(s);
    for (auto x : vs)
        cout << x << el;
    return;
}