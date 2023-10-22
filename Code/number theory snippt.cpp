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
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define all(a) a.begin(), a.end()
#define F(x, a) for (auto x : a)

#define pii pair<int, int>
#define ff first
#define ss second
#define mp make_pair

#define vb vector<bool>
#define vi vector<int>
#define pb push_back

template <typename T> using V = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;

inline int exp(int a, int b)
{
    int x;
    for (x = 1; b; a *= a, b >>= 1)
        x *= (a * (b & 1) + !(b & 1));
    return x;
}

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // int __t ; cin >> __t; while (__t--)
    solve();

    return 0;
}

pair<int, int> Egcd(int a, int b)
{
    if (b == 0)
        return make_pair(1, 0);

    pair<int, int> xy = Egcd(b, a % b);
    int x = xy.second;
    xy.second = xy.first - xy.second * (a / b);
    xy.first = x;

    return xy;
}

pair<int, int> Egcd(int a, int b, int c)
{
    if ((a == 0 and b == 0) or c % __gcd(a, b) != 0)
    {
        // If solution not Possible then return {0, 0}
        return make_pair(0, 0);
    }

    pair<int, int> xy = Egcd(a, b);
    int k = (c / __gcd(a, b));

    xy.first *= k;
    xy.second *= k;
    
    /*
    	you can shift the solution by
    	x = x + (b/g)*t 
    	y = y - (b/g)*t
    	where t is any integer(+/-ve) and g = __gcd(a, b);
    */

    return xy;
}


const int N = 1e7 + 1;
int divisor[N] = {0};

void primeDivisor()
{
    divisor[1] = 1;
    for (int i = 2, j; i < N; i++)
        if (divisor[i] == 0)
        {
            for (j = i; j < N; j += i)
                if (divisor[j] == 0)
                    divisor[j] = i;
        }

    return;
}

// All the Prime Divisor of any interger(<= 1e7) (e.g, 45 = 3*3*5)
vector<int> APD(int a)
{
    vector<int> ans;
    while (a > 1)
    {
        ans.pb(divisor[a]);
        a /= divisor[a];
    }
    sort(ans.begin(), ans.end());

    return ans;
}

int gcd(int a, int b)
{
    if (a == 0 and b == 0)
        return 0;
    else if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else
        return __gcd(a, b);
}

int expo(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    
    return res;
}





void solve()
{
    
    return;
}
