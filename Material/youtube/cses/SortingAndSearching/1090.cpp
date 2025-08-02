// Problem: Ferris Wheel
// URL: https://cses.fi/problemset/task/1090/
// Memory Limit: 512 MB
// Time Limit: 1000 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, w;
    cin >> n >> w;

    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar, ar + n);

    int ans = 0;
    for (int i = 0, j = n - 1; i <= j; ans++, j--) {
        if (i < j and ar[i] + ar[j] <= w) i++;
    }
    cout << ans;

    return 0;
}