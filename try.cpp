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

void solve()
{
    int a;
    cin >> a;
    if (a != 1)
    {
        int b = sqrt(a);
        if (a == (b * b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;
    return;
}

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     int t;
//     cin >> t;
//     queue<int> q;
//     vector<int> n;
//     for (int i = 0; i < t; i++)
//     {
//         int temp;
//         cin >> temp;
//         n.push_back(temp);
//         q.push(temp);
//     }
//     int t_temp = q.front();
//     int i_t = t;

//     int count = 0;
//     for (int i = 1; i <= t_temp; i++)
//     {

//         if (t_temp % i == 0)
//             ++count;

//         if ((count > 3) || ((count < 3) && (i == t_temp)))
//         {
//             cout << "NO" << endl;
//             q.pop();
//             t_temp = q.front();
//             i = 0;
//             count = 0;
//             continue;
//         }

//         if ((count == 3) && (i == t_temp))
//         {
//             cout << "YES" << endl;
//             q.pop();
//             t_temp = q.front();
//             i = 0;
//             count = 0;
//             continue;
//         }
//     }

//     return 0;
// }


