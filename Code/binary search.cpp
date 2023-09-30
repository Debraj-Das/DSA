#include <bits/stdc++.h>
using namespace std;

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // int __t ; cin >> __t; while (__t--)
    solve();

    return 0;
}

int binary(int lo, int hi, function<bool(int)> check)
{
    int ans = hi + 1, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ans;
}
/* How to used the binary function in binary search operation
1. lower ranage = lo , higher range = hi ;
2. check function => which respect the solution space is NNNNNYYYYY(first no then yes)

auto check = [&](int mid) {
    // body of the check function
    // return true or false depend on mid ;
}

    int ar[n] ;
eg. int ans = binary(0, n - 1, [&](int i) { return ar[i] < ar[0]; });

*/

int binarySearch(int lo, int hi, function<int(int)> check)
{
    int ans = hi + 1, mid, val;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        val = check(mid);

        if (!val)
        {
            ans = mid;
            break;
        }
        (val > 0) ? (lo = mid + 1) : (hi = mid - 1);
    }
    return ans;
}

void solve()
{
    int ar[] = {13, 3, 34, 23, 45};
    sort(ar, ar + 5);

    int val = binarySearch(0, 4, [&](int mid) { return (23 - ar[mid]); });

    if (val == 2)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }

    return;
}
