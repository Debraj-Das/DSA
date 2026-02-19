#include <bits/stdc++.h>
using namespace std;

inline int getIthBit(int n, int i) { return (((n >> i) & 1) ? 1 : 0); }

inline int clearIthBit(int n, int i) {
    int mask = ~(1 << i);
    n = (n & mask);
    return n;
}

inline int setIthBit(int n, int i) {
    int mask = (1 << i);
    n = (n | mask);
    return n;
}

inline int updateIthBit(int n, int i, int v) {
    clearIthBit(n, i);
    int mask = (v << i);
    return (n | mask);
}

inline int clearLastIBits(int n, int i) {
    int mask = ((-1) << i);
    return (n & mask);
}

inline int clearBitsInRange(int n, int i, int j) {
    int a = ((-1) << (j + 1));
    int b = (1 << i) - 1;

    int mask = (a | b);
    return (n & mask);
}

inline int noOfBits(int n) {
    int ans = 0;
    while (n > 0) {
        n = (n & (n - 1));
        ans++;
    }
    return ans;
}

inline bool checkTwoPower(int n) { return (n > 0) and (n & (n - 1)) == 0; }

inline bool checkFourPower(int n) {
    return (n > 0 and (n & (n - 1)) == 0 and n % 3 == 0);
}

int32_t main() { return 0; }
