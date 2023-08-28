#include <bits/stdc++.h>

using namespace std;

#define el '\n'

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int ans = a[0];
    for (int i = 0; i < n; i++)
        a[i] -= ans;

    for (int i = 0; i < n; i++)
        if (a[i] != i)
        {
            ans += i;
            break;
        }

    cout << ans << el;

    return 0;
}