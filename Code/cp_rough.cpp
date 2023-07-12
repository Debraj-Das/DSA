/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "C:\Users\debra\AppData\Local\Programs\cpeditor\Header\debug.h"
#endif
/*
    Function ::
    1. bug(a,b,c,...) (any no of single variable)
    2. darr(array , n) (print the all the array element)
    3. dmat(mat,row,col) (print full matrix)
    4. bstl(x) (all the STL DataType )
*/
#ifndef ONLINE_JUDGE
#include "C:\Users\debra\AppData\Local\Programs\cpeditor\Header\random.h"
#endif

/*
 * Random Int generator in range [l = INT_MIN , r = INT_MAX]
 * Random number generator
 * Random vector
 * Random array
 * Random shuffle the vector
 * Random shuffle the array
 * Repeate the code n seconds

 * Usage:
 ~ l = left range(default = 0) and r = right range(default = 1e9)
 1. randomNumber(l, r) -> return a random number between l and r
 2. randomVector(n, l, r) -> return a random vector of size n with elements between l and r
 3. randomArray(arr, n, l, r) -> return a random array of size n with elements between l and r
 4. shuffle(v) -> shuffle the vector v
 5. shuffle(arr, n) -> shuffle the array arr

# 6. time(n) -> repeat the code n seconds

*/

using namespace std;

#define int long long
#define el '\n'
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    register int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

inline void solve()
{
    /*time(0.0001)
    {
        int b = randomNumber(23, 43);
        bug(b);
    }*/
    register int n;
    cin >> n;
    int arr[n];
    f(i, 0, n) cin >> arr[i];
    int sum = 1;
    f(i, 0, n) sum += arr[i];
    cout << sum << el;

    return;
}
