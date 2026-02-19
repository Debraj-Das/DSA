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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 0; i < TC; i++) {
        // cout<<"case "<<(i+1)<<": ";
        solve();
        cout << '\n';
    }

    return 0;
}

/*
   Description :
      Basic operations on square matrices.
      Usage :
         Matrix<int, 3> A;
         A.d = {{{{1, 2, 3}}, {{4, 5, 6}}, {{7, 8, 9}}}};
         vector<int> vec = {1, 2, 3};
         vec = (AˆN)*vec;
*/
template <class T, int N>
struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};

    M operator*(const M& m) const {
        M a;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    a.d[i][j] += d[i][k] * m.d[k][j];
                }
            }
        }

        return a;
    }

    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ret[i] += d[i][j] * vec[j];
            }
        }

        return ret;
    }

    M operator^(ll p) const {
        assert(p >= 0);

        M a, b(*this);
        for (int i = 0; i < N; i++) a.d[i][i] = 1;

        while (p) {
            if (p & 1) a = a * b;
            b = b * b;
            p >>= 1;
        }

        return a;
    }
};

void solve() {
    int n;
    cin >> n;

    Matrix<int, 3> A;
    A.d = {{{{1, 2, 3}}, {{4, 5, 6}}, {{7, 8, 9}}}};
    vector<int> vec = {1, 2, 3};
    vec = (A ^ n) * vec;

    for (int i = 0; i < n; i++) {
        cout << vec[i] << sp;
    }

    return;
}
