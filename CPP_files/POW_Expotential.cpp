/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

// #include <bits/stdc++.h>
// using namespace std;
// void solve();

// int32_t main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     clock_t z = clock();

//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve(); // solve the problem inside of drive function for test cases.

//     cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

//     return 0;
// }

// void solve()
// {
//     int b;
//     long double a, val = 1;
//     cin >> a >> b;
//     while (b)
//     {
//         if (b & 1)
//             val *= a;
//         a = (a * a);
//         b >>= 1;
//     }
//     cout << val << endl;
//     return;
// }

/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;
string solve(int, int, int);

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
    while (t--) // solve the problem inside of drive function for test cases.
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}


//* my solve which gives OVERFLOW of value
// long long int power(int a, int b)
// {
//     long long int x = 1;
//     for (x = 1; b; a *= a, b >>= 1)
//         if (b & 1)
//             x *= a;
//     return x;
// }

// string solve(int A, int B, int C)
// {
//     long long int p1 = power(A, C), p2 = power(B, C);
//     if (p1 > p2)
//         return ">";
//     else if (p1 < p2)
//         return "<";
//     else
//         return "=";
// }

//* Teacher solution (nice solution)
string solve(int A, int B, int C)
{
    int sign1 = (A < 0 && C % 2);
    int sign2 = (B < 0 && C % 2);
    string ans;
    if (sign1 != sign2)
    {
        ans = sign1 ? "<" : ">";
    }
    else
    {
        if (abs(A) == abs(B))
        {
            ans = "=";
        }
        else if ((abs(A) < abs(B)) ^ sign1)
        {
            ans = "<";
        }
        else
        {
            ans = ">";
        }
    }
    return ans;
}
