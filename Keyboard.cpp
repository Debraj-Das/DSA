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

void right_shift(string &s)
{
    for (int i = 0; s[i]; ++i)
    {
        switch (s[i])
        {
        case 'w':
            s[i] = 'q';
            break;
        case 's':
            s[i] = 'a';
            break;
        case 'x':
            s[i] = 'z';
            break;
        case 'e':
            s[i] = 'w';
            break;
        case 'd':
            s[i] = 's';
            break;
        case 'c':
            s[i] = 'x';
            break;
        case 'r':
            s[i] = 'e';
            break;
        case 'f':
            s[i] = 'd';
            break;
        case 'v':
            s[i] = 'c';
            break;
        case 't':
            s[i] = 'r';
            break;
        case 'g':
            s[i] = 'f';
            break;
        case 'b':
            s[i] = 'v';
            break;
        case 'y':
            s[i] = 't';
            break;
        case 'h':
            s[i] = 'g';
            break;
        case 'n':
            s[i] = 'b';
            break;
        case 'u':
            s[i] = 'y';
            break;
        case 'j':
            s[i] = 'h';
            break;
        case 'm':
            s[i] = 'n';
            break;
        case 'i':
            s[i] = 'u';
            break;
        case 'k':
            s[i] = 'j';
            break;
        case ',':
            s[i] = 'm';
            break;
        case 'o':
            s[i] = 'i';
            break;
        case 'l':
            s[i] = 'k';
            break;
        case '.':
            s[i] = ',';
            break;
        case 'p':
            s[i] = 'o';
            break;
        case ';':
            s[i] = 'l';
            break;
        case '/':
            s[i] = '.';
            break;

        default:
            break;
        }
    }
    return;
}

void left_shift(string &s)
{
    for (int i = 0; s[i]; ++i)
    {
        switch (s[i])
        {
        case 'q':
            s[i] = 'w';
            break;
        case 'a':
            s[i] = 's';
            break;
        case 'z':
            s[i] = 'x';
            break;
        case 'w':
            s[i] = 'e';
            break;
        case 's':
            s[i] = 'd';
            break;
        case 'x':
            s[i] = 'c';
            break;
        case 'e':
            s[i] = 'r';
            break;
        case 'd':
            s[i] = 'f';
            break;
        case 'c':
            s[i] = 'v';
            break;
        case 'r':
            s[i] = 't';
            break;
        case 'f':
            s[i] = 'g';
            break;
        case 'v':
            s[i] = 'b';
            break;
        case 't':
            s[i] = 'y';
            break;
        case 'g':
            s[i] = 'h';
            break;
        case 'b':
            s[i] = 'n';
            break;
        case 'y':
            s[i] = 'u';
            break;
        case 'h':
            s[i] = 'j';
            break;
        case 'n':
            s[i] = 'm';
            break;
        case 'u':
            s[i] = 'i';
            break;
        case 'j':
            s[i] = 'k';
            break;
        case 'm':
            s[i] = ',';
            break;
        case 'i':
            s[i] = 'o';
            break;
        case 'k':
            s[i] = 'l';
            break;
        case ',':
            s[i] = '.';
            break;
        case 'o':
            s[i] = 'p';
            break;
        case 'l':
            s[i] = ';';
            break;
        case '.':
            s[i] = '/';
            break;

        default:
            break;
        }
    }
    return;
}

/*
time complexity of this operation is 26*length_of_string
but we do this by only lenth_of_string by using hashing
*/

void solve()
{
    char c;
    string s;
    cin >> c >> s;
    if (c == 'R')
        right_shift(s);
    else
        left_shift(s);
    cout << s << el;
    return;
}