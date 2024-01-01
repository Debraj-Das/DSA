// Problem: B5 - Hackathons
// URL: https://dmoj.ca/problem/dmpg17b5
// Memory Limit: 64 MB
// Time Limit: 1000 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>

const int N = 1000001;
int Time[N];

int32_t main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n;
    std::cin >> n;

    for (int i = 0, t, w; i < n; i++)
    {
        std::cin >> t >> w;
        Time[t] = (Time[t] > w ? Time[t] : w);
    }

    for (int i = 0, mx = 0; i < N; i++)
    {
        mx = (Time[i] > mx ? Time[i] : mx);
        Time[i] = mx;
    }

    int q, T;
    std::cin >> q;

    while (q--)
    {
        std::cin >> T;
        std::cout << Time[T] << '\n';
    }

    return 0;
}
