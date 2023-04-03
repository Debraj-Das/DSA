#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int r, c;
    cin >> r >> c;
    cout << ((min(r, c) % 2) ? "Akshat" : "Malvika") << '\n';
    return 0;
}