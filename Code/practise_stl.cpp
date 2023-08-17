// /*
// অভিজ্ঞতা একটি কঠিন শিক্ষক,
// সে প্রথমে তোমার পরীক্ষা নেয় এবং
// পরে তার পাঠ দেয়।
// */
//
// #include <bits/stdc++.h>
// using namespace std;
//
// #define el '\n'
// #define sp ' '
//
// void Pair();
// void Vector();
//
// int32_t main()
// {
// // Pair();
// Vector();
//
// return 0;
// }
//
// /*	Iterator brief discussion
//
// in iterator there are four function ->
// 1. begin() -> first element of the container
// 2. end() -> after the last element of container
// 3. rbegin() -> last element of the container
// 4. rend() -> before the first element of the container
//
// if you want to travel whole container then used the for each loop
// */
//
// void Vector()
// {
// // intialised the vector
// vector<int> v; // intiallised the empty vector and you inialised by any other vector
// // push element in back of vector
// v.push_back(10);
// v.push_back(12);
// // for each loop
// for (int &i : v)
// cout << i << sp;
// cout << el;
// // pop of last element (pop the back element)
// v.pop_back();
// // print the last element
// cout << *(v.rbegin()) << el;
// }
//
// void Pair()
// {
// // how to declear the pair of int and string
// pair<int, string> p;
// p = {2, "avec"};
// cout << p.first << sp << p.second << el;
// // you can create any type of variable pair like pair<set<int>,vector<int>> p ;
// }
//

/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define sp ' '

#define f(i, a, b) for (int i = a; i < (b); i++)
#define fr(i, a, b) for (int i = a; i >= (b); i--)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define ff first
#define ss second
#define pii pair<int, int>

#define vi vector<int>
#define pb push_back

template <typename T> using V = vector<T>;

template <typename T> using pq = priority_queue<T>;

template <typename T1, typename T2> using umap = unordered_map<T1, T2>;

template <typename T> using uset = unordered_set<T>;

inline int exp(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

void solve()
{
    V<int> a(3, 0);
    for (auto v : a)
        cout << v << sp;
    cout << el;

    return;
}
