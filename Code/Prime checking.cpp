// Problem: B. Prime checking
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms

/*
    "Arise! Awake! And stop not until the goal is reached."
    "You cannot believe in God until you believe in yourself."
    "Talk to yourself once in a day, otherwise you may miss meeting an intelligent person in this world."
    "We are what our thoughts have made us; so take care about what you think.
                    Words are secondary. Thoughts live; they travel far."
                                                        by Swami Vivekananda
*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';

inline void solve();

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   // int __t ; cin >> __t; while (__t--)
   solve();

   return 0;
}

void solve()
{
   long long n;
   cin >> n;

   if (n == 1 or (n != 2 and n%2 == 0))
   {
      cout << "NO";
      return;
   }

   for (long long i = 3; i * i <= n; i += 2)
      if (n % i == 0)
      {
         cout << "NO";
         return;
      }

   cout << "YES" << el;

   return;
}

/*
  After Solving the any problems write some point on notebook for future refferences
    1. Go through the solution and overall logic flows

    2. Go through editiorial and other implementation

    3. Make note ->
        a. Didied the into keys steps
        b. Topic and level(out of 100)
        etc..

    4. What new points you discover from this problems
        a. insight
        b. intuition
        c. process (steps of both)

    5. Solution Date and Submission time (reading , thinking , implementation , total)

    6. submit count and solve by youself ?
*/