// Problem: Permutation Order
// URL: https://cses.fi/problemset/task/3397
// Memory Limit: 512 MB
// Time Limit: 1000 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';

inline void solve();
inline void solve2();

ll fact[21];

void calc() {
    ll fc = 1;
    fact[0] = 1;
    for (int i = 1; i < 21; i++) {
        fc *= i;
        fact[i] = fc;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    calc();
    int TC = 1, t;
    cin >> TC;
    for (int i = 0; i < TC; i++) {
        // cout<<"case "<<(i+1)<<": ";
        cin >> t;
        if (t == 1)
            solve();
        else
            solve2();
        cout << '\n';
    }

    return 0;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    k--;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        ar[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        ll bs = fact[n - 1 - i];
        int id = k / bs;
        cout << ar[id] << sp;
        ar.erase(ar.begin() + id);
        k %= bs;
    }

    return;
}

void solve2() {
    int n;
    cin >> n;

    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    ll k = 0;
    vector<int> av(n);
    for (int i = 0; i < n; i++) {
        av[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        int id = -1;
        for (int j = 0; j < (int)av.size(); j++) {
            if (av[j] == ar[i]) {
                id = j;
                break;
            }
        }

        k += fact[n - 1 - i] * id;
        av.erase(av.begin() + id);
    }

    cout << (k + 1);

    return;
}
