// Problem: Grid Path Description
// URL: https://cses.fi/problemset/task/1625
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

string s;
const int N = 7;
int ans = 0;
bool grid[N][N];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
map<char, int> dir = {
    {'D', 0},
    {'R', 1},
    {'U', 2},
    {'L', 3},
};

inline bool vaild(int x, int y) {
    return (x >= 0 and y >= 0 and x < N and y < N and grid[x][y] == false);
}

inline bool condition0(int x, int y) {
    bool up = vaild(x - 1, y);
    bool down = vaild(x + 1, y);
    bool left = vaild(x, y - 1);
    bool right = vaild(x, y + 1);

    return (up == down) and (left == right);
}

inline bool condition1(int x, int y, int dx, int dy) {
    bool corner = vaild(x + dx, y + dy);
    bool up = vaild(x + dx, y);
    bool right = vaild(x, y + dy);

    return (corner == false) and (up == right) and (up == true);
}

void rec(int x, int y, int ind) {
    if (x == N - 1 and y == 0) {
        ans += (ind == N * N - 1) ? 1 : 0;
        return;
    }

    if ((ind == N * N - 1) or condition0(x, y) or condition1(x, y, -1, -1) or
        condition1(x, y, -1, 1) or condition1(x, y, 1, -1) or
        condition1(x, y, 1, 1))
        return;

    grid[x][y] = true;

    if (s[ind] != '?') {
        int nx = x + dx[dir[s[ind]]];
        int ny = y + dy[dir[s[ind]]];
        if (vaild(nx, ny)) {
            rec(nx, ny, ind + 1);
        }

        grid[x][y] = false;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (vaild(x + dx[i], y + dy[i])) {
            rec(x + dx[i], y + dy[i], ind + 1);
        }
    }

    grid[x][y] = false;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;

    rec(0, 0, 0);
    cout << ans;

    return 0;
}
