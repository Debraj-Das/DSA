// Problem: E. Alternating Array
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/329103/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   int n;
   cin >> n;

   int a = 0;
   for (int i = 0, x; i < n; i++)
   {
      cin >> x;
      a += ((i & 1) ^ (x < 0));
   }

   cout << min(a, n - a) << el;

   return 0;
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